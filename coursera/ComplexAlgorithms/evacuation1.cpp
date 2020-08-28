#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using std::vector;

/* This class implements a bit unusual scheme for storing edges of the graph,
 * in order to retrieve the backward edge for a given edge quickly. */
 using namespace std;
    struct Edge {
        int from, to, capacity, flow;
    };
class FlowGraph {
public:

private:
    /* List of all - forward and backward - edges */
    vector<Edge> edges;

    /* These adjacency lists store only indices of edges in the edges list */
    vector<vector<size_t> > graph;

public:
    explicit FlowGraph(size_t n): graph(n) {}

    void add_edge(int from, int to, int capacity) {
        /* Note that we first append a forward edge and then a backward edge,
         * so all forward edges are stored at even indices (starting from 0),
         * whereas backward edges are stored at odd indices in the list edges */
        Edge forward_edge = {from, to, capacity, 0};
        Edge backward_edge = {to, from, 0, 0};
        graph[from].push_back(edges.size());
        edges.push_back(forward_edge);
        graph[to].push_back(edges.size());
        edges.push_back(backward_edge);
    }

    size_t size() const {
        return graph.size();
    }

    const vector<size_t>& get_ids(int from) const {
        return graph[from];
    }

    const Edge& get_edge(size_t id) const {
        return edges[id];
    }

    void add_flow(size_t id, int flow) {
        /* To get a backward edge for a true forward edge (i.e id is even), we should get id + 1
         * due to the described above scheme. On the other hand, when we have to get a "backward"
         * edge for a backward edge (i.e. get a forward edge for backward - id is odd), id - 1
         * should be taken.
         *
         * It turns out that id ^ 1 works for both cases. Think this through! */
        edges[id].flow += flow;
        edges[id ^ 1].flow -= flow;
    }
};

FlowGraph read_data() {
    int vertex_count, edge_count;
    std::cin >> vertex_count >> edge_count;
    FlowGraph graph(vertex_count);
    for (int i = 0; i < edge_count; ++i) {
        int u, v, capacity;
        std::cin >> u >> v >> capacity;
        graph.add_edge(u - 1, v - 1, capacity);
    }
    return graph;
}

int way[10000];
bool path(int x,int y, FlowGraph& Graph){
    memset(way,-1,sizeof way);
    queue<int> q;
    q.push(x);
    way[x] = x;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u == y) return true;
        for (int v: Graph.get_ids(u)){
            Edge cap = Graph.get_edge(v);
            if(way[v] != -1 and cap.capacity > 0){
                way[v] = u;
                q.push(v);
            }
        }
    }
    return false;
}
int max_flow(FlowGraph& graph, int from, int to) {
    int flow = 0;
    while(path(from,to, graph)){
        int mn = 1e9;
        for (int i = to; i != from; i = way[i])
            mn = min(mn,graph.get_edge(i).capacity);
        flow += mn;
        for (int i = to; i != from; i = way[i])
            graph.add_flow(to,mn);
    }
    return flow;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    FlowGraph graph = read_data();

    std::cout << max_flow(graph, 0, graph.size() - 1) << "\n";
    return 0;
}
