#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
queue<pair<int,int> > q;
char c[1010][1010];
int d[1010][1010];

int main(){
	memset(d,-1,sizeof d);	
	int n,m;	
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> c[i][j];

	int a,b; cin >> a >> b;

	q.push({a-1,b-1});
	d[a-1][b-1] = 0;
	int ans = -1;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(c[x][y] == 't'){
			if(d[x][y] > ans){
	//			cout << x << " " << y << d[x][y] << endl;
				ans = d[x][y];	
			}
		}
		for (int i = 0; i < 4; ++i){
			int u = x+dx[i];
			int v = y+dy[i];
			if(u >= 0 and u < n and v >= 0 and v < m and d[u][v] == -1 and c[u][v] != 'X'){
				d[u][v] = d[x][y] + 1;
				q.push({u,v});
			}
		}
	}	
	if(ans == -1) cout << "mejor vamos a comer al nikis" << endl;
	else cout << "maxima distancia: " << ans << endl;
	return 0;
}
