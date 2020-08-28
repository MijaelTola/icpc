#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <climits>

using namespace std;

map<int,vector<pair<int,int> > > G;
map<int,int> way;
set<int> vis;
int m;
bool bfsa(int s,int t){
	queue<int> q;
	q.push(s);
	way[s] = s;
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(u == t) return true;
		for (pair<int,int> i: G[u]){
			if(!vis.count(i.first) and i.second > 0){
				way[i.first] = u;
				q.push(i.first);
				vis.insert(i.first);
			}
		}
	}
	return false;	
}
int max_flow(int s,int t){
	int ans = 0;
	while(bfs(s,t)){
		cout << "asdfasdfasdf \n";
		int mn = INT_MAX;
		for (int v = t; v != s; v = way[v]){
			int u = way[v];
			mn = min(mn,G[u][v].second);
		}
		ans += mn;
		for (int v = t; v != s; v = way[v]){
			int u = way[v];
			G[u][v].second -= mn;
			G[v][u].second += mn;
		}
	}
	return ans;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		m = -1;
		for (int i = 0; i < n; ++i){
			int x,y; cin >> x >> y;
			G[x].push_back({y,1});
			G[y].push_back({x,1});
			G[-1].push_back({x,1});
			G[INT_MAX].push_back({y,1});
		}
		cout << max_flow(0,INT_MAX);
	}
	return 0;
}
