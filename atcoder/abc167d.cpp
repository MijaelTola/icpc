#include <bits/stdc++.h>

using namespace std;

int v[200010];
int vis[200010];

int main() {
    
    int n;
    long long k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    int p = 1;
    
    vector<int> a,b;
    int cnt = 0;
    while(!vis[p]) {
        vis[p]++;
        p = v[p];
    }
    
    vis[p] = 2;
    p = 1;
    while(vis[p] != 2) {
        b.push_back(p);
        cnt++;
        p = v[p];
    }
    memset(vis, 0, sizeof vis);
    
    while(!vis[p]) {
        vis[p]++;
        a.push_back(p);
        p = v[p];
    }
    
    if(k < cnt) {
        cout << b[k] << "\n";
        return 0;
    }

    k -= cnt;
    long long mod = a.size();
    cout << a[(k % mod)] << "\n";
    return 0;
}

