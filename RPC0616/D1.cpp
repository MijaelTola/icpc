#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;


char c[110][110];
int r[110][110];
bool vis[110][110];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m;

void verify(int x,int y){
	 for (int i = 0; i < 4; ++i){
                int u = dx[i] + x;
                int v = dy[i] + y;
                if(u >= 0 and u < n and v >= 0 and v < m) continue;
		r[x][y] = 1;
		break;
	}
}
int fill(int x,int y){
	int ans = -1;
	int count = r[x][y] + 1;
	for (int i = 0; i < 4; ++i){
		int u = dx[i] + x;
		int v = dy[i] + y;
		if(u >= 0 and u < n and v >= 0 and v < m){
			r[u][v] = min(r[u][v],count);
			ans = max(ans,r[u][v]);	
		}
	}
	return ans;
}
void clean(){
	for (int i = 0; i < 110; ++i)
		for (int j = 0; j < 110; ++j){
			r[i][j] = 1e8;
			vis[i][j] = false;
		}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	queue<pair<int,int> > q;
	clean();
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j){
			cin >> c[i][j];
			if(c[i][j] == '.'){
				r[i][j] = 0;
				q.push({i,j});
			}
		}
	q.push({0,0});
	q.push({n-1,m-1});
	q.push({0,m-1});
	q.push({n-1,0});
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(vis[x][y]) continue;
		vis[x][y] = true;
		if(c[x][y] == 'T') verify(x,y);
		fill(x,y);
		for(int i = 0; i < 4; ++i){
			int u = dx[i] + x;
			int v = dy[i] + y;
			if(u >= 0 and u < n and v >= 0 and v < m and !vis[u][v])
				q.push({u,v});
		}
	}
	int rings = -1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) rings = max(rings,r[i][j]);
	
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if(rings < 10){
				if(r[i][j] == 0) cout << "..";
				else cout << "." << r[i][j];
			}else{
				if(r[i][j] == 0) cout << "...";
				else{
					if(log10(r[i][j])+1 < 2) cout << ".." << r[i][j];
					else cout << "."  << r[i][j];
				}
			}
		}
		cout << "\n";
	}
	return 0;
}
