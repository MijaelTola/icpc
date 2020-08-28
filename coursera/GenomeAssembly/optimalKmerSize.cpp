#include <bits/stdc++.h>

using namespace std;

vector<string> v;
map<string, int> mp;
vector<string> reads(300010);
int in[300010];
int out[300010];
bool vis[300010];
vector<int> G[300010];
int cur;

void build(const vector<string> &Reads, int k) {
        cur = 0;
        for (auto s: Reads) {
            string a = s.substr(0, k - 1);
            string b = s.substr(1, k - 1);
            if(!mp.count(a)) {
                reads[cur] = a;
                mp[a] = cur++;
            }
            if(!mp.count(b)) {
                reads[cur] = b;
                mp[b] = cur++;
            }
            int x = mp[a];
            int y = mp[b];
            G[x].push_back(y);
            in[y]++;
            out[x]++;
        }
}

void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for (int v: G[u])
        dfs(v);
}

bool ver(int k) {
    memset(vis, 0, sizeof vis);
    memset(in, 0, sizeof in);
    memset(out, 0, sizeof out);
    for (int i = 0; i < 300010; ++i) 
        G[i].clear();
    
    vector<string> kmers;
    set<string> st;
    for (auto x: v) {
        for (int i = 0; i <= (int)x.size() - k; ++i) {
            kmers.push_back(x.substr(i,k));
        }
    }
    build(kmers, k);
    bool flag = 1;
    dfs(0);
    int cnt = 0;
    for (int i = 0; i < cur; ++i) {
        flag &= in[i] == out[i];
        cnt += vis[i];
    }
    return cnt == cur;
}

int main() {

    string s;
    int dk = 0;
    while (cin >> s) {
        v.push_back(s);
        dk = s.size();
    }
    
    //cout << ver(3) << "\n";
    int a = 0, b = dk + 1;

    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(ver(mid)) a = mid;
        else b = mid;
    }

    cout << a << "\n";
    return 0;
}


