#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int NEUTRO = 0; // a null value for my ST
int vec[maxn];
vector<tuple<int,int,int> >G[maxn]; //the graph
int n;
int dp[2][maxn];
int tot = 0LL;
struct hld{
	int ncad; // store actual number of chain
	int root; // the root of a tree generally 0 or 1
	int pos; // pos of node in chain
	
	int sz[maxn]; // store the subsize of subtrees
	int depth[maxn]; //depth of the node, useful for LCA via HLD
	int parent[maxn]; // useful for LCA 
	int where[maxn]; // where chain is the node? 
	//int edgepos[maxn]; // if the value is on the edge: stored in a node
	int chainIdx[maxn]; // position in the chain of the node
	int head[maxn]; // the head of the i-th chain
	//int val[maxn]; // if the value is on the edge
	
	void init(){//settings value, and process de HLD
		root = 0;
		ncad = 0;
		pos = 0;
		for(int i = 0; i <=n; i++){
			where[i] = head[i] = -1;
		}
		depth[root] = 0;
		dfs(root , -1, 0, 0);
		descompose(root);
	}
	
	
	///init descomposition
	void dfs(int u,int pu, int a, int  b){
		dp[0][u] = a;
		dp[1][u] = b;
		//cout << u + 1 << " " << a << " " << b << endl;
		sz[u] = 1; //init the sz of this subtree
		parent[u] = pu; // assign the parent
		for(int i = 0; i < G[u].size(); i++){
			int v = get<0>(G[u][i]);
			long long aa = get<1>(G[u][i]);
			long long bb = get<2>(G[u][i]);
			if ( v == pu )continue;
			//edgepos[idx[u][i]] = v;
			depth[v] = depth[u] + 1;
			dfs(v,u, a + aa, b + bb);
			sz[u] += sz[v];
		}
	}
	//descompose graph in HLD descomposition
	void descompose(int u){
		if( head[ncad] == -1)head[ncad] = u; // the head of ncad is u
		where[u] = ncad; // assign where tu node
		//val[pos] = cost; cost another parameter in descompose for graphs with values in edges
		chainIdx[u] = pos++; //assing pos to this node
		int maxi = -1, sc = -1; //finding a special child
		for(auto node:G[u]){
			int  v = get<0>(node);
			if( sz[v] > maxi && where[v] == -1){
				maxi = sz[v];
				sc = v;
			}
		}
		if(sc != -1)descompose(sc);
		//light nodes here:
		for(auto node:G[u]){
			int v = get<0>(node);
			if(where[v] == -1){
				ncad++;
				descompose(v);
			}
		}
	}
	///end descomposition
	
	int lca(int u,int v){
		while(where[u]!=where[v]){
			if(depth[ head[ where[u] ] ] > depth[ head[ where[v] ] ])u = parent[ head[ where[u] ] ];
			else v = parent[ head[ where[v] ] ]; 
		}
		return depth[u] < depth[v] ? u:v;
	}
	
	
	int Q(int u,int v){
		int L = lca(u,v);
		//cout << "LCA LINE "<< u << " " << v << " " << L << endl;
		return tot - dp[1][v] - dp[0][u] + dp[0][L] + dp[1][L];
	}
}HLD;
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

int main(){
	int cases = in();
	while(cases--){
		n = in();
		for(int i = 0; i < n; i++)G[i].clear();
		tot = 0LL;
		for(int i = 1, u,v,a,b ; i < n; i++){
			u = in(), v = in(), a = in(), b = in();
			u--,v--;
			G[u].emplace_back(v,a,b);
			G[v].emplace_back(u,b,a);
			tot += (a + b);
		}
		//cout << "TOA " << tot << endl;
		HLD.init();
		int question;
		cin >> question;
		for(int i = 0, t, u ,v; i < question; i++){
			u = in(), v = in();
			//cin >> u >> v;
			u--,v--;
			printf("%d\n",HLD.Q(u,v));
		}
	}
}

