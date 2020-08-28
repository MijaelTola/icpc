#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

vector<pair<int,int> > G[100010];
queue<pair<int,int> > q;
int way[100010];
bool vis[1000010];
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--){
		while(!q.empty()) q.pop();
		for (int i = 0; i < 100010; ++i){
			way[i] = -1;
			vis[i] = false;
			G[i].clear();
		}
		int n;
		cin >> n;
		for (int i = 0; i < n-1; ++i){
			int x,y,p; cin >> x >> y>> p;
			G[x].push_back({y,p});
			G[y].push_back({x,p});		
		}
		int s,t;
		cin >> s >> t;
		q.push({s,1e9});
		while(!q.empty()){
			int u = q.front().first;
			int cost = q.front().second;
			q.pop();
			if(u == t){
				cout << cost << "\n"; break;
			}
			for (pair<int,int> i: G[u]){
				if(!vis[i.first]){
					vis[i.first] = true;
					int mn = min(cost,i.second);
					q.push({i.first,mn});
				}
			}
		}
		
	}
	return 0;
}
