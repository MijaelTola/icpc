#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> G[100010];
int v[100010];
pair<int,int>  bfs(int x){
	int ans = -1;
	int node;
	queue<pair<int,int> > q;
	q.push({x,0});
	vector<bool> vis(100010,false);
	while(!q.empty()){
		int u = q.front().first;
		int c = q.front().second;
		if(c > ans){
			ans = c;
			node = u;
		}
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for (int i: G[u]){
			if(!vis[i]){
				q.push({i,c+1});
			}
		}
	}
	return pair<int,int> (node,ans);
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	
	for (int i = 0; i < n-1; ++i){
		int x,y; cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	pair<int,int> x = bfs(1);
	int a = x.first;
	//cout << a << endl;
	pair<int,int> y = bfs(a);
	int b = y.first;
	int diameter = y.second;
	cout << diameter/2+1 << endl;
}
