#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> G[1000010];
vector<int> sorted;
int z[1000010];
int ini[1000010];
int fin[1000010];
int val[1000010];
int pos = 0;

struct segmentTree {
    int n;
    vector<int> tree, lazy;

    segmentTree(int _) {
        n = _;
        tree.resize(5 * n);
        lazy.resize(5 * n);
    };

    void create_tree(int node, int start, int end){
        if(start == end){
            tree[node] = val[start];
        }
        else{
            int mid = (start+end)/2;
            create_tree(2*node, start, mid);
            create_tree(2*node+1, mid+1, end);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }

    void push(int node, int start, int end){
        tree[node] = end - start + 1 - tree[node];
        if(start != end){
            lazy[2*node] ^= 1;
            lazy[2*node+1] ^= 1;
        }
        lazy[node]=0;
    }

    void update(int node, int start, int end, int l, int r){
        if(lazy[node]){
            push(node, start, end);
        }  
        if(start > r || end < l){
            return;
        }
        if(l <= start && end <= r){
            lazy[node] ^= 1;
            if(lazy[node]){
                push(node, start, end);
            }
            return;
        }
        int mid = (start+end)/2;
        update(2*node, start, mid, l, r);
        update(2*node+1, mid+1, end, l, r);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    int query(int node, int start, int end, int l, int r){ 
        if(start > r || end < l){
            return 0;
        }
        if(lazy[node]){
            push(node, start, end);
        }
        if(l <= start && end <= r){
            return tree[node];
        }
        int mid = (start+end)/2;
        return query(2*node, start, mid, l, r) + query(2*node+1, mid+1, end, l, r);
    }

};




void dfs(int u, int p = -1) {
    sorted.push_back(u);
    ini[u] = pos;
    fin[u] = pos;
    val[pos] = z[u];
    pos++;
    for (int v: G[u]) {
        if(v == p) continue;
        dfs(v, u);
    }
    fin[u] = pos;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        x--;
        G[x].push_back(i);
    }

    for (int i = 0; i < n; ++i)
        cin >> z[i];

    dfs(0);

    segmentTree st(pos);

    st.create_tree(1, 0, n - 1);

    int q;
    cin >> q;

    while(q--) {
        string c;
        int x;
        cin >> c >> x;
        x--;
        if(c[0] == 'p') {
            int l = ini[x];
            int r = fin[x];
            st.update(1, 0, n - 1, l, r - 1);
        } else {
            int l = ini[x];
            int r = fin[x];
            cout << st.query(1, 0, n - 1, l, r - 1) << "\n";
        }
    }
    return 0;
}

