#include <bits/stdc++.h>

using namespace std;

vector<int> G[400010];
int vis[400010];

int f(int u) {
    
    if(vis[u] == 2) return 1;

    for (int v: G[u]) {
    
    }
}
int main() {
    
    int n;
    cin >> n;

    set<string> st;
    unordered_map<string, int> mp;
    vector<string> v;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
        string ini = s.substr(0, 3);
        string fin =  s.substr(s.size() - 3, 3);
        st.insert(ini);
        st.insert(fin);
    }
    
    int ini = 0;
    for (auto x: st) {
        mp[x] = ini++;
    }

    for (int i = 0; i < n; ++i) {
        string s = v[i];
        string ini = s.substr(0, 3);
        string fin =  s.substr(s.size() - 3, 3);
        int a = mp[ini];
        int b = mp[fin];
        G[a].push_back(b);
    }

    
    return 0;
}

