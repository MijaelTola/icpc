
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

    for (int i = 2; i < 1000100; i++) {
        if(!p[i]) primes.push_back(i);
    }

}

void factor(int n){
    int index = 0;
    int pf = primes[0];
    num.clear();
    while(pf*pf <= n){
        while(n%pf==0){
            num.push_back(pf);
            if(!vis[pf]) ans.push_back(pf);
            vis[pf] = 1;
            n /= pf;
        }
        pf = primes[++index];
    }
    if(n != 1) {
        num.push_back(n);
        if(!vis[n]) ans.push_back(n);
        vis[n] = 1;
    }
    pr.push_back({num[0], num[1]});
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    criba();
    int t;
    cin >> t;
    
    for (int k = 1; k <= t; ++k) {
        int n,r,ix,iy;
        clear();
        cin >> r >> n;
        bool first = 1;
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            factor(x);
            if(first) {
                ix = num[0];
                iy = num[1];
            }
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < (int)ans.size(); ++i) 
            alpha[ans[i]] = (char)(i + 'A');
        cout << "Case #" << k << ": ";
        int last = -1; 
        for (int i = 0; i < n; ++i) {
            if(pr[i].first == pr[i + 1].first or pr[i].first == pr[i + 1].second) {
                cout << alpha[pr[i].second];
                last = pr[i].first;
            }
            else {
                cout << alpha[pr[i].first];
                last = pr[i].second;
            }
        }
        cout << alpha[last] << "\n";
    }

    return 0;
}

