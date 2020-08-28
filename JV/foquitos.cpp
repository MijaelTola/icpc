#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

vector<int> G[100010];
int mark[100010];
set<int> ans;
bool vis[100010];
queue<int> q;
int way[100010];
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--){
		for (int i = 0; i < 100010; ++i){
			vis[i] = false;
			G[i].clear();
			way[i] = -1;
			mark[i] = false;
		}
		ans.clear();
		int n,m;
		cin >> n >> m;
		for (int i = 0; i < n-1; ++i){
			int x,y; cin >> x >> y;
			G[x].push_back(y);	
			G[y].push_back(x);	
		}
		
		q.push(1);
		way[1] = 1;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for (int i: G[u]){
				if(!vis[i]){
					vis[i] = true;
					way[i] = u;
					q.push(i);
				}
			}
		}
		
		
		for (int i = 0; i < m; ++i){
			int x; cin >> x;
			for (int v = x; v != 1; v = way[v]){
				if(mark[v]) break;
				mark[v] = true;
				ans.insert(v);
			}
		}
		if(ans.size()>0) cout << ans.size()+1 << "\n";
		else cout << ans.size() << "\n";
	}
	return 0;
}
