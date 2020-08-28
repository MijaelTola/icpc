#include <bits/stdc++.h>

using namespace std;

string s;
int vis[60];
int mark[60];
int mark2[60];
int opt[2510][60];
int dp[2510][60];
vector<int> G[2510];

bool isLetter(char x) {
    return 'a' <= x and x <= 'z';
}

int build() {
    stack<int> st;
    for (int i = 0; i < (int)s.size(); ++i) {
        if(isLetter(s[i]))
            st.push(i);
        else {
            int k = 2;
            while(k--) {
                int id = st.top();
                st.pop();
                if(!isLetter(s[id]) and s[id] == s[i]) {
                    for (int x: G[id]) G[i].push_back(x);
                    G[id].clear();
                } else G[i].push_back(id);
            }
            st.push(i);
        }
    }
    return st.top();
}

void print() {
    for (int i = 0; i < (int)s.size(); ++i) {
        if(G[i].size()) {
            cout << s[i] << ": ";
            for (int j: G[i])
                cout << s[j] << " ";
            cout << "\n";
        }
    }
}


bool dfs(int u, vector<vector<int> > &G2) {
    if(vis[u]) return 0;
    vis[u] = 1;
    for (int v: G2[u]) {
        if(mark[v] == -1 or dfs(mark[v],G2)) {
            mark[u] = v;
            mark[v] = u;
            return 1;
        }
    }
    return 0;
}

int mbm(vector<vector<int> > &G2) {
    memset(mark, -1, sizeof mark);
    memset(vis, 0, sizeof vis);
    
    int ans = 0;
    for (int i = 0; i < 26; ++i)
        if(mark[i] == -1) {
            memset(vis, 0, sizeof vis);
            dfs(i, G2);
        }

    for (int i = 0; i < 26; ++i)
        if(mark[i] != -1) ans++;
    return ans;
}

bool only (int id, vector<vector<int> > &G2, int l) {
    for (int i = 0; i < l; ++i)
        mark2[i] = mark[i];

    int pl = mark[id];
    mark[pl] = -1;
    memset(vis, 0, sizeof vis);
    bool flag = dfs(mark[id], G2);

    for (int i = 0; i < l; ++i)
        mark[i] = mark2[i];

    return flag;
};

int f(int u, int c) {
    if(G[u].size() == 0) {
        opt[u][s[u] - 'a'] = 1;
        if(c == s[u] - 'a') return 1;
        return 1e9;
    }

    int &ans = dp[u][c];
    if(ans != -1) return ans;

    int cnt = 0;
    ans = 0;

    vector<int> a(28); 
    vector<vector<int> > G2(50);

    for (int v: G[u]) 
        if(isLetter(s[v])) 
            a[s[v] - 'a'] = 1;

    for (int i = 0; i < 26; ++i)
        cnt += a[i];

    int l = 27;

    for (int i = 0; i < (int)G[u].size(); ++i) {
        int v = G[u][i];
        if(!isLetter(s[v])) {
            int mn = 1e9;
            for (int i = 0; i < 26; ++i) 
                mn = min(mn, f(v,i));
            
            for (int i = 0; i < 26; ++i) {
                if(f(v,i) == mn and opt[v][i] and a[i]) 
                    G2[i].push_back(l);
                
                if(opt[v][i]) opt[u][i] |= 1;
            }
            ans += mn;
            l++;
        } 
    }
    
    int M = mbm(G2);
    int cur = 0;
    for (int i = 0; i < 27; ++i) 
        if((mark[i] == -1 or only(i, G2, l)) and a[i]) {
            opt[u][i] = 1;
            cur++;
        }

    int cur2 = 0;

    for (int i = 0; i < 27; ++i)
        cur2 += opt[u][i];

    if(cur < cnt and opt[u][c] and cur2 != 1) return 1e9;
    cur = 0;
    for (int i = 0; i < 27; ++i)
        cur += opt[u][i];

    return ans = cnt + ans - (M != 0) + 1;
}

int main() {
    memset(dp, -1, sizeof dp);

    cin >> s;

    int root = build();

    int ans = 1e9;

    for (int i = 0; i < 26; ++i) 
        ans = min(ans, f(root,i));
    

    cout << ans << "\n";
    return 0;
}

