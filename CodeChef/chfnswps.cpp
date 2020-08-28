#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        long long n;
        cin >> n;
        map<long long,long long> mp,a,b,c;
        long long mn = 1e10;
        for (long long i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            a[x]++;
            c[x]++;
            mn = min(mn, 1LL * x);
        }

        for (long long i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            b[x]++;
            c[x]++;
            mn = min(mn, 1LL * x);
        }

        bool flag = 1;
        long long df = 0;

        for (auto p: c) {
            if(a[p.first] == b[p.first]) {
                a.erase(p.first);
                b.erase(p.first);
                continue;
            }
            long long cur = p.second / 2;
            if(a[p.first] < b[p.first]) {
                b[p.first] = abs(b[p.first] - cur);
                df += b[p.first];
                a.erase(p.first);
            } else {
                a[p.first] = abs(a[p.first] - cur);
                df += a[p.first];
                b.erase(p.first);
            }
            flag &= (p.second % 2 == 0);
        }
        
        if(!a.count(mn) and !b.count(mn)) a[mn] = 0;
        if(!flag) {
            cout << "-1\n";
            continue;
        }

        if(df == 0) {
            cout << "0\n";
            continue;
        }

        long long ans = 0;
        auto solve = [&] (map<long long, long long> &a, map<long long, long long> &b) {
            auto p = *a.begin();
            long long dif = p.second;
            
            while(dif--) {
                auto p2 = *b.rbegin();
                long long cnt = p2.second;
                cnt--;
                ans += p.first;
                if(!cnt) b.erase(p2.first);
                else b[p2.first] = cnt;
                df-=2;;
            }

            a.erase(a.begin());
            
            if(df <= 0) return;
            while(a.size() and b.size() and 2 * p.first <= (*a.rbegin()).first 
                    and 2 * p.first <= (*b.rbegin()).first and df % 2 == 0) {
                auto p2 = *b.rbegin();
                long long cnt = p2.second;
                cnt--;
                ans += p.first;
                if(!cnt) b.erase(p2.first);
                else b[p2.first] = cnt;
                auto p3 = *a.rbegin();
                cnt = p3.second;
                cnt--;
                ans += p.first;
                if(!cnt) a.erase(p3.first);
                else a[p3.first] = cnt;
                df -= 2;
            }
        };
        
        if((*a.begin()).first < (*b.begin()).first) solve(a,b);
        else solve(b,a);
        
        while(df > 0) {
            if((*a.begin()).first < (*b.begin()).first) {
                auto p2 = *b.rbegin();
                long long cnt = p2.second;
                cnt--;
                if(!cnt) b.erase(p2.first);
                else b[p2.first] = cnt;
                auto p3 = *a.begin();
                cnt = p3.second;
                cnt--;
                ans += p3.first;
                if(!cnt) a.erase(p3.first);
                else a[p3.first] = cnt;
                df-=2;
            } else {
                auto p2 = *b.begin();
                long long cnt = p2.second;
                cnt--;
                if(!cnt) b.erase(p2.first);
                else b[p2.first] = cnt;
                auto p3 = *a.rbegin();
                cnt = p3.second;
                cnt--;
                ans += p2.first;
                if(!cnt) a.erase(p3.first);
                else a[p3.first] = cnt;
                df-=2;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
 
