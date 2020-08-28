#include <bits/stdc++.h>
using namespace std;

int n;
const int maxn = 1e5 + 100;
const int NEUTRO = 0;
int vec[maxn];
vector<int>G[2 * maxn];
vector<int> adj[maxn];
int op(int a, int b) {
	return a + b;
}
struct SegmentTree {
	int s[4 * maxn];
	int lazy[4 * maxn];
	void build(int id = 1,int l = 0,int r = n){
		if(r - l < 2){	//	l + 1 == r
			s[id] = 0;
			return ;
		}
		int mid = (l+r)/2;
		build(id * 2, l, mid);
		build(id * 2 + 1, mid, r);
		s[id] = s[id * 2] + s[id * 2 + 1];
	}
	void upd(int id,int l,int r,int x){
		lazy[id] += x;
		s[id] += (r - l) * x;
	}
	//A function to pass the update information to its children :
	void shift(int id,int l,int r){//pass update information to the children
		int mid = (l+r)/2;
		upd(id * 2, l, mid, lazy[id]);
		upd(id * 2 + 1, mid, r, lazy[id]);
		lazy[id] = 0;// passing is done
	}
	//A function to perform increase queries :
	void increase(int x,int y,int v,int id = 1,int l = 0,int r = n){
		if(x >= r or l >= y)	return ;
		if(x <= l && r <= y){
			upd(id, l, r, v);
			return ;
		}
		shift(id, l, r);
		int mid = (l+r)/2;
		increase(x, y, v, id * 2, l, mid);
		increase(x, y, v, id*2+1, mid, r);
		s[id] = s[id * 2] + s[id * 2 + 1];
	}
	//(We should call increase(l r x))
	int sum(int x,int y,int id = 1,int l = 0,int r = n){
		if(x >= r or l >= y)	return 0;
		if(x <= l && r <= y)	return s[id];
		shift(id, l, r);
		int mid = (l+r)/2;
		return sum(x, y, id * 2, l, mid) +
			   sum(x, y, id * 2 + 1, mid, r);
	}
	void init() {
		build();
	}
	void update(int l, int r, int val) {
		increase(l,r,val);
	}
	int query(int l,int r) {
		return sum(l, r);
	}
};
struct hld{
	int ncad;
	int root;
	int pos;
	
	int sz[2 * maxn];
	int depth[2 * maxn];
	int parent[2 * maxn]; 
	int where[2 * maxn]; 
	int chainIdx[2 * maxn];
	int head[2 * maxn];
	SegmentTree tree;
	void init(){
		root = 0;
		ncad = 0;
		pos = 0;
		for(int i = 0; i < 2 * maxn; i++){
			where[i] = head[i] = -1;
		}
		depth[root] = 0;
		dfs(root , -1);
		tree.init();
		descompose(root);
	}
	
	
	void dfs(int u,int pu){
		//cout << u << " PU " << pu << endl;
		sz[u] = 1;
		parent[u] = pu;
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i];
			if ( v == pu )continue;
			depth[v] = depth[u] + 1;
			dfs(v,u);
			sz[u] += sz[v];
		}
	}
	void descompose(int u){
		if( head[ncad] == -1)head[ncad] = u;
		where[u] = ncad;
		chainIdx[u] = pos++;
		int maxi = -1, sc = -1;
		for(int v:G[u]){
			if( sz[v] > maxi && where[v] == -1){
				maxi = sz[v];
				sc = v;
			}
		}
		if(sc != -1)descompose(sc);
		for(int v:G[u]){
			if(where[v] == -1){
				ncad++;
				descompose(v);
			}
		}
	}
	int update(int u,int v, int val){
		int vChain = where[v];
		int ans = NEUTRO;
		while(true){
			int uChain = where[u];
			if(uChain == vChain){
				tree.update( chainIdx[v] + 1, chainIdx[u] + 1, val);
				return 0;
			}
			int hu = head[uChain];
			tree.update(chainIdx[hu], chainIdx[u] + 1, val);
			u = parent[hu];
		}
	}
	int query(int u,int v){
		int vChain = where[v];
		int ans = NEUTRO;
		while(true){
			int uChain = where[u];
			if(uChain == vChain){
				return op(ans, tree.query( chainIdx[v] + 1, chainIdx[u] + 1) );
			}
			int hu = head[uChain];
			ans = op( ans, tree.query(chainIdx[hu], chainIdx[u] + 1) );
			u = parent[hu];
		}
	}
	int lca(int u,int v){
		//cout << u << " carajo " << v << endl;
		while(where[u] != where[v]){
			//cout << where[u] << " " << where[v] << endl;
			if(depth[ head[ where[u] ] ] > depth[ head[ where[v] ] ])u = parent[ head[ where[u] ] ];
			else v = parent[ head[ where[v] ] ]; 
		}
		return depth[u] < depth[v] ? u:v;
	}
	int Q(int u, int v){
		int L = lca(u,v);
		return query(u, L) + query(v, L) + tree.query(chainIdx[L], chainIdx[L] + 1);
	}
	void U(int u, int v, int val) {
		int L = lca(u, v);
		update(u, L, val);
		update(v, L, val);
		tree.update(chainIdx[L], chainIdx[L] + 1,val);
	}
}HLD;


int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int q;
	cin >> n >> q;
	for (int i = 1, u, v; i < n;i++) {
		cin >> u >> v;
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	HLD.init();
	while (q--) {
		int u, v, a, b;
		cin >> u >> v >> a >> b;
		u--,v--;a--,b--;
		HLD.U(u, v, 1);
		cout << HLD.Q(a, b) << "\n";
		HLD.U(u, v, -1);
	}
}
