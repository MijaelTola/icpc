#include <bits/stdc++.h>

using namespace std;

vector<int> v[1010];
bool vis[1010];
int main() {

    int b;
    int n;
    cin >> b >> n;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int x; cin >> x;
            v[i].push_back(x);   
        }
    }

    vector<int> c;
    c = v[0];
    int ans = 1e9, id = -1;
    for (int i = 1; i < n; ++i) {
        vector<int> a;
        for (int j = 0; j < (int)v[i].size(); ++j) {
            queue<int> q;
            for (int x: c) q.push(x);
            int mn = 1e9;
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                if(u > v[i][j]) {
                    mn = min(mn, u);
                    continue;
                }
                for (int x: c) q.push(u + x);
            }
            if(mn >= b and mn < ans) {
                ans = mn;
                id = v[i][j];
            }
            a.push_back(mn);
        }
        c = a;
    }
    if(id != -1)cout << id << "\n";
    else cout << "impossible\n";

    return 0;
}
//x % k = z
//c % k = m
//x % k % c % k = z % m
