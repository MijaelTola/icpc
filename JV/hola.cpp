#include <bits/stdc++.h>
using namespace std;
int color[100010];
vector<int>G[100010];
int parent[100010];
vector<int>path;
bool cycle(int u){
	color[u] = 1;
	bool check = false;
	for(int v:G[u]){
		parent[v] = u;
		if(color[v] == 1){
			check = true;
		}
		check |= cycle(v);
	}
	color[u] = 2;
}
int main(){
	int n;
	cin >> n;
	for(int i = 0,u; i < n; i++){
		cin >> u;
		u--;
		G[i].push_back(u);
	}
}


