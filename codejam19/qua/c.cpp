#include <bits/stdc++.h>

using namespace std;

bool p[1000100];
bool vis[1000100];
char alpha[1000100];
vector<int> primes, num, ans;
vector<pair<int,int> > pr;

void clear() {
    num.clear();
    ans.clear();
    pr.clear();
    memset(p, 0, sizeof p);
    memset(vis, 0, sizeof vis);
}

void criba() {
    for (int i = 2; i < 1000100; ++i) {
        if(p[i]) continue;
        for (int j = i + i; j < 1000100; j += i) 
            p[j] = 1;
    }

    for (int i = 2; i < 1000100; i++) 
        if(!p[i]) primes.push_back(i);

}

int main() {
    //ios::sync_with_stdio(false); cin.tie(0);
    criba();
    int t;
    cin >> t;
    int ix,iy;
    for (int k = 1; k <= t; ++k) {
    bool first = 1;
        clear();
        map<int,char> mp;
        int n,r;
        cin >> r >> n;
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            for (int curP: primes) {
                if(x % curP == 0) {
                    int a1 = x / curP;
                    int a2 = curP;
                    if(a1 <= r and a2 <= r) {
                        pr.push_back({a1, a2});
                        if(!mp.count(a1)) mp[a1] = 'a';
                        if(!mp.count(a2)) mp[a2] = 'a';
                    }
                    break;
                }
            }
        }
        char let = 'A';
        for (pair<int,char> u: mp) 
            mp[u.first]= let++;

        for (auto u: pr)
            cout <<u.first << " " << u.second << " test\n";
        cout << "Case #" << k << ": ";
        int last = n - 1; 
        for (int i = 0; i < (int)pr.size() - 1; ++i) {
            if(pr[i].first == pr[i + 1].first 
                    or pr[i].first == pr[i + 1].second) 
                cout << mp[pr[i].second];
            else cout << mp[pr[i].first];
        }

        if(pr[last].first == pr[last -1].first or 
                pr[last].first == pr[last - 1].second) 
            cout << mp[pr[last].first] << mp[pr[last].second];
        else cout << mp[pr[last].second] << mp[pr[last].first];
        cout << "\n";
    }

    return 0;
}

