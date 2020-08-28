#include <bits/stdc++.h>

using namespace std;

int in[200010];
int p[200010];

void init() {for (int i = 0; i < 200010; ++i) p[i] = i;}
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]);};
void merge(int x, int y) { p[find(y)] = find(x);};

int main() {

    int n,m,s,ds,t,dt;
    cin >> n >> m;

    vector<vector<int> > G(n + 10);

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    cin >> s >> t >> ds >> dt;
    
    vector<pair<int,int > > v;
    priority_queue<pair<int,int> > q;

    for (int i = 1; i <= n; ++i) 
        if(i != s and i != t) v.emplace_back(i == s or i == t,i);
        else q.push({0,i});

    sort(v.begin(), v.end());

    init();
    vector<pair<int,int> > ans;

    for (auto p: v) {
        for (int x: G[p.second]) {
            if(find(x) != find(p.second)) {
                merge(x, p.second);
                ans.emplace_back(x, p.second);
                in[x]++;
                in[p.second]++;
            }
        }
    }

    while(!q.empty()) {
        int u = q.top().second;
        int cur = -q.top().first;
        q.pop();

        for (int x: G[u]) {
            if(find(x) != find(u)) {
                merge(x,u);
                ans.emplace_back(x,u);
                cur++;
                if(u == s) {
                    if(cur <= ds) q.push({cur, u});
                } else {
                    if(cur <= dt) q.push({cur, u});
                }
                break;
            }
        }
    }

    if(in[s] > ds or in[t] > dt) return cout << "No\n",0;
    cout << "Yes\n";
    for (auto p: ans)
        cout << p.first << " " << p.second << "\n";

    return 0;
}

