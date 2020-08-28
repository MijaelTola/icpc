#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

vector<int> G[1010];
int way[1010];
pair<int,int> bfs(int u){
	queue<pair<int,int> > q;
	vector<int> vis(1010,false);
    memset(way,-1,sizeof way);
	int mx = -1;
	int node;
	q.push({u,0});
    way[u] = u;
	while(!q.empty()){
		int u = q.front().first;
		int c = q.front().second;
		q.pop();
		if(c > mx){
			mx = c;
			node = u;
		}
		for (int i: G[u]){
			if(!vis[i]){
               vis[i] = true;
               way[i] = u;
				q.push({i,c+1});
			}
		}
	}	
	return {node,mx};
}
int main(){
	queue<int> q;
	vector<int> vis(1010,false);
	int n; cin >> n;
	for (int i = 0; i < n-1; ++i){
		int x,y; cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	pair<int,int> x = bfs(1);
	pair<int,int> findDiameterNode = bfs(x.first);
	int node = findDiameterNode.first;
	int diameter = findDiameterNode.second;
    //cout<< node << " " << diameter << endl;
    for (int v = node; v != x.first; v = way[v]){
    //    cout << v << " ASDF"  << endl;
        vis[v] = true;
    }
    vis[x.first] = true;
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        if (!vis[i]) ans++;
    }
    cout << ans*2+diameter << "\n";
	return 0;
}

