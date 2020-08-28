#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

vector<int> G[100100];
vector<int> GT[100100];
vector<int> G2[100100];
int scc[100100];
bool vis[100100];
int cont[100100];
stack<int> s;
int n;
void dfs(int u){
	//cout<<"entra con "<<u<<endl;
	for (int x:G[u]){
		if(!vis[x]){
			vis[x] = true;
			dfs(x);
		}
	}
	s.push(u);
}

void dfs2(int u, int num){
	cont[num]++;
	for (int x: GT[u]){
		if(scc[x] == -1){
			scc[x] = num;
			dfs2(x,num);
		}
	}
}

void clean(){
	for (int i = 0; i < 100000; ++i){
	//	vis[i] = false;
		scc[i] = -1;
	//	G[i].clear();
	//	GT[i].clear();
	//	G2[i].clear();
	}
}
int kosaraju(){
	//cout<<"asd"<<endl;
	for (int i = 1; i <= n; ++i){
		if(!vis[i]){
			vis[i] = true;
			dfs(i);
		}
	}
	//cout<<s.size()<<endl;
	int color = 0;
	while(!s.empty()){
		int u = s.top(); s.pop();
		if(scc[u] == -1){
			scc[u] = ++color;
			dfs2(u,color);
		}
	}
	return color;

}
void build(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<G[i].size();j++){
			//cout << i << " " << scc[i] << " " << G[i][j]  << " " << scc[G[i][j]] << endl;
			if(scc[i]!=scc[G[i][j]])
			G2[scc[G[i][j]]].push_back(scc[i]);
		}
	}
}
int main(){
	//ios::sync_with_stdio(false); cin.tie(0);
	clean();
	scanf("%d",&n);
	queue<pair<int,int> > q;
	for (int i = 1; i <= n; ++i){
		int x; scanf("%d",&x);
		G[i].push_back(x);
		GT[x].push_back(i);
	}

	int color = kosaraju();
	build();	
	int node;
	int mx = -1;
	for (int i = 1; i <= color; ++i){
	      if(cont[i] > mx ){
		mx = cont[i];
		node = i;
		}
	}
	memset(vis,false,sizeof vis);
	int ans = 0;
	q.push({node,0});
	vis[node] = true;
	while(!q.empty()){
		int u = q.front().first;
		int c = q.front().second;
		q.pop();
		ans = max(c,ans);
		for (int i: G2[u]){
			if(!vis[i]){
				vis[i] = true;
				q.push({i,c+1});
			}
		}
	}
	//cout << cont[node] << " " << ans << endl;
	printf("%d\n",cont[node]+ans);
	//cout<< cont[node] + ans << "\n";
	return 0;
}
