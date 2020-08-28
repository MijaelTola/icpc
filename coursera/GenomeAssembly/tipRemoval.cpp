#include <bits/stdc++.h>

using namespace std;

struct Assembler {
    int N, cur, k, n;
    map<string, int> mp;
    vector<string> reads, Reads;
    vector<int> in,out,vis,count, din, dis;
    vector<vector<int> >  G;
    vector<pair<pair<int,int>, int> > contings;
    set<pair<int,int> > e;

    void clean() {
        for (int i = 0; i < N; ++i) {
            G[i].clear();
            in[i] = out[i] = vis[i] = 0;
            mp.clear();
        }
    }

    void build(const vector<string> &Reads, int k) {
        clean();
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
            if(a == b or e.count({x,y})) continue;
            e.insert({x,y});
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
    
    vector<string> createKmers(int dk) {
        vector<string> kmers;
        set<string> st;

        for (auto x: Reads) { 
            for (int i = 0; i <= (int)x.size() - dk; ++i) {
                st.insert(x.substr(i, dk));
            }
        }
    
        for (auto x: st) {
            kmers.push_back(x);
        }

        return kmers;
    }

   
    bool ver(int dk) {
        build(createKmers(dk), dk);

        bool flag = 1;
        dfs(0);
        int cnt = 0;
        for (int i = 0; i < cur; ++i) {
            flag &= in[i] == out[i];
            cnt += vis[i];
        }
        return cnt == cur;
    }

    void findOptimalKmer() {
        int a = 0, b = k + 1;

        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(ver(mid)) a = mid;
            else b = mid;
        }

        k = a;

    }

    vector<int> path;
    vector<vector<int> > paths;
    void dfsB(int u, int t) {
        if(in[u] > 1) paths.push_back(path);
        if(t == 0) 
            return;
        
        for (int v: G[u]) {
            if(vis[v]) continue;
            path.push_back(v);
            vis[v] = 1;
            dfsB(v, t - 1);
            vis[v] = 0;
            path.pop_back();
        }
    }

    bool isDisjoint(const vector<int> &a, const vector<int> &b) {
        set<int> da,db;

        for (int i = 1; i < (int)a.size() - 1; ++i)
            da.insert(a[i]);

        int join = 0;

        for (int i = 1; i < (int)b.size() - 1; ++i) {
            join += da.count(b[i]);
            db.insert(b[i]);
        }

        for (int i = 1; i < (int)a.size() - 1; ++i) {
            join += db.count(a[i]);
        }

        return join == 0 and a[0] == b[0] 
            and a.back() == b.back() and da.size() + 2 == a.size() and db.size() + 2 == b.size();
    };

    int bubbleDetector(int t) {
        for (int i = 0; i < cur; ++i)
            vis[i] = 0;
        int cnt = 0;
        for (int i = 0; i < cur; ++i) 
            if(out[i] > 1) {
                paths.clear();
                path.clear();
                path.push_back(i);
                vis[i] = 1;
                dfsB(i, t);
                vis[i] = 0;
                path.pop_back();
                
                for (int j = 0; j < (int)paths.size(); ++j) {
                    for (int k = j + 1; k < (int)paths.size(); ++k) {
                        auto x = paths[j];
                        auto y = paths[k];
                        if(isDisjoint(x, y)) {
                            cnt++;
                        }
                    }
                }
            }
            
        return cnt;
    }

    void contingFinder() {
        fill(vis.begin(), vis.end(), 0);
        vector<vector<int> >  adj = G;
        for (int i = 0; i < cur; ++i) {
            if((in[i] == 0 or out[i] > 1) and !vis[i]) {
                stack<pair<int, int> > s;
                int u = i;
                int ini = u;
                int d = 0;
                s.push({u, ini});

                while(!s.empty()) {
                    vis[u] = 1;
                    if(G[u].size()) {
                        int vv = G[u].back();
                        d++;
                        G[u].pop_back();
                        s.push({u, ini});
                        u = vv;
                        if(in[vv] != 1 or out[vv] != 1) {
                            contings.push_back({{ini,vv},d});
                            ini = vv;
                        }
                    } else {
                        u = s.top().first;
                        ini = s.top().second;
                        s.pop();
                        d--;
                    }
                }
            }
        }
        G = adj;

    }

    int removingTips() {
        set<pair<int,int> > ed;
        for (auto p: contings) {
            int a,b;
            a = p.first.first;
            b = p.first.second;
            if(in[a] == 0 or out[b] == 0) {
                fill(vis.begin(), vis.end(), -1);
                queue<pair<int,int> > q;
                q.push({a, 0});
                vis[a] = -1;

                while(!q.empty()) {
                    int u = q.front().first;
                    int d = q.front().second;
                    q.pop();
                    if(u == b) break;
                    for (int v: G[u]) {
                        if(vis[v] == -1) {
                            vis[v] = u;
                            q.push({v, d + 1});
                        }
                    }
                }
             
                int p = b;
                int lim = 4;
                while(vis[p] != -1 and lim--) {
                    ed.insert({min(p, vis[p]), max(p, vis[p])});
                    p = vis[p];
                }
            }
        }
        return ed.size();
    }

    void printGraph() {
        for (int i = 0; i < cur; ++i) {
            cout << reads[i] << ": ";   
            for (int j: G[i]) 
                //cout << i << " " << j << "\n";
                cout << reads[j] << " ";
            cout << "\n";
        }
    }

    Assembler(int n, vector<string> Read, int dk) {
        reads.resize(n);
        in.resize(n);
        out.resize(n);
        vis.resize(n, 0);
        G.resize(n);
        count.resize(n, 0);
        din.resize(n, 0);
        dis.resize(n, 0);
        N = n;
        Reads = Read;
        k = dk;
        //findOptimalKmer();
        auto Z = createKmers(k);
        build(Z, k);
    }
};

int main() {

    vector<string> v;
    string s;

    while(cin >> s) v.push_back(s);

    Assembler A(100010, v, 3);
    //A.printGraph();
    A.contingFinder();
    cout << A.removingTips() << "\n";
    return 0;
}

