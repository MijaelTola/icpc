#include <bits/stdc++.h>

using namespace std;

class  MaxFlow {
    public:
        struct edge {
            int from, to, cap, flow, lb;
        };

    private:
        vector<edge> edges;
        vector<vector<size_t> > G;
        vector<int> out, in;

        size_t last_edge;

    public:
        explicit  MaxFlow(size_t n, size_t m, size_t last_edge)
            : G{n}, last_edge{last_edge} {
                edges.reserve(m * 2);
            }

        void set_last_edge() {
            last_edge = edges.size();
        }

        void set_int_out_lbs( vector<int> out_lbs,  vector<int> in_lbs) {
            out =  move(out_lbs);
            in =  move(in_lbs);
        }

        void print() {
            for(size_t i = 0; i < last_edge; i += 2) {
                cout << edges[i].flow + edges[i].lb << "\n";
            }
        }

        void add_edge(int from, int to, int cap, int lb) {
            edge u = { from, to, cap, 0, lb };
            edge v = { to, from, 0, 0, lb };
            G[from].push_back(edges.size());
            edges.push_back(u);
            G[to].push_back(edges.size());
            edges.push_back(v);
        }

        size_t size() const {
            return G.size();
        }

        const vector<size_t>& get_ids(int from) const {
            return G[from];
        }

        const edge& get_edge(size_t id) const {
            return edges[id];
        }

        void add_flow(size_t id, int flow) {
            edges[id].flow += flow;
            edges[id ^ 1].flow -= flow;
        }

        int lbs_sum = 0;
};

void bfs(const  MaxFlow& G, int s, int t, vector<int>& way) {
    t = 0;
    t++;
    queue<int> q;
    q.push(s);

    fill(way.begin(), way.end(), -1);

    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (auto id : G.get_ids(cur)) {

            const  MaxFlow::edge& e = G.get_edge(id);

            if (way[e.to] == -1 && e.cap > e.flow && e.to != s) {
                way[e.to] = id;
                q.push(e.to);
            }
        }
    }
}

int max_flow(MaxFlow& G, int s, int t) {
    int flow = 0;
    vector<int> way(G.size());

    do {
        bfs(G, s, t, way);
        if (way[t] != -1) {
            int min_flow = numeric_limits<int>::max();
            for (int u = way[t]; u != -1; u = way[G.get_edge(u).from]) {
                min_flow =  min(min_flow, G.get_edge(u).cap - G.get_edge(u).flow);
            }
            for (int u = way[t]; u != -1; u = way[G.get_edge(u).from]) {
                G.add_flow(u, min_flow);
            }
            flow += min_flow;
        }

    } while (way[t] != -1);

    return flow;
}

int main() {

    int n, M;
    cin >> n >> M;
    int m = M;

    M += n * 2; 
    n += 2;     
    MaxFlow G(n, M, m * 2);
    vector<int> out(n), in(n);

    for (int i = 0; i < m; ++i) {
        int u, v, lb, cap;
        cin >> u >> v >> lb >> cap;
        G.add_edge(u, v, cap-lb, lb);
        out[u] += lb;
        in[v] += lb;
        G.lbs_sum += lb;
    }

    for(int i = 1, s = 0, t = n - 1; i < t; ++i) {
        G.add_edge(s, i, in[i], in[i]);
        G.add_edge(i, t, out[i], out[i]);
    }

    G.set_int_out_lbs( move(out),  move(in)); 
    int flow = max_flow(G, 0, G.size() - 1);

    if(flow != G.lbs_sum) return cout << "NO\n", 0;
    cout << "YES" << '\n';
    G.print();
    return 0;
}
