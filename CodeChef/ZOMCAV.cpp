#include <bits/stdc++.h>

using namespace std;

int t;
long long c[100010];
long long l[100010];
long long r[100010];
long long a[100010];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    while(t--) {
        map<long long, long> mp;
        for (int i = 0; i < 100010; ++i)
            c[i] = l[i] = r[i] = a[i] = 0;
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) 
            cin >> c[i];


        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            mp[x]++;
        }

        for (int i = 0; i < n; ++i) {
            l[i]++, r[i]++;
            if(i + c[i] + 1 < n) l[i + c[i] + 1]--;
            if(i - c[i] - 1 >= 0) r[i - c[i] - 1]--;
        }

        for (int i = 1; i < n; ++i) 
            l[i] += l[i - 1];
        
        for (int i = n - 1; i >= 0; i--) 
            r[i] += r[i + 1];
        
        bool flag = 1;
        for (int i = 0; i < n; ++i) {
            long long val = (l[i] + r[i] - 1);
            if(mp[val] > 0) mp[val]--;
            else flag = 0;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

