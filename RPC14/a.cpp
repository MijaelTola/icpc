#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define UNVISITED -1
#define VISITED 1
#define EXPLORED 2
#define max_n 100010

int dfs_num[max_n];
int dfs_parent[max_n];

vector<vi> AdjList;
map<string,int> mapper;
int n;

bool graphCheck(int u){
	dfs_num[u] = EXPLORED;
	
	bool sw = 0;
	
	for(int j = 0; j < (int)AdjList[u].size(); j++){
		int v = AdjList[u][j];
		
		if(dfs_num[v] == UNVISITED){
			dfs_parent[v] = u;
			sw = sw | graphCheck(v);
		}else if(dfs_num[v] == EXPLORED){
			return 1;
		}
	}
	dfs_num[u] = VISITED;
	return sw;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	AdjList.assign(max_n, vi());
	
	string a, b;
	char op;
	
	int k = 0;
	while(n--){
		cin>>a>>op>>b;
		if(!mapper[a])mapper[a] = ++k;
		
		if(!mapper[b]) mapper[b] = ++k;
		
		if(op == '<'){
			AdjList[mapper[a]].push_back(mapper[b]);
		}else{
			AdjList[mapper[b]].push_back(mapper[a]);
		}
	}
	
	memset(dfs_num, UNVISITED, sizeof dfs_num);
	memset(dfs_parent, -1, sizeof dfs_parent);
	
	bool sw = 0;
	for(int i = 1; i <= k; i++){
		if(dfs_num[i] == UNVISITED){
			sw = sw | graphCheck(i);
		}
	}
	
	if(sw) cout<<"impossible\n";
	else cout<<"possible\n";
	
	return 0;
}
