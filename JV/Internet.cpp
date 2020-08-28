#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

queue<int> q;
vector<int> G[1010];
set<int> ans;
bool vis[1010];

int main(){
	memset(vis,false,sizeof vis);
	int n,m,p;
	cin >> n >> m >> p;
	
	for (int i = 0; i < m; ++i){
		int x,y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	q.push(p);
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		ans.insert(u);
		for (int v: G[u]){
			if(!vis[v])
				q.push(v);
		}
	}
	cout << ans.size() << endl;
	for (int i : ans) cout << i << " ";
	cout << endl;
	return 0;
}
