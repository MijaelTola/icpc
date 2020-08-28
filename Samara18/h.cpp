#include <bits/stdc++.h>

using namespace std;

int n,m,d;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> d;
	queue<pair<int,int> > q;
	char c[n][m];
	int v[n][m];
	int dis[n][m];
	memset(v, -1, sizeof v);
	memset(dis, -1, sizeof dis);
	int xi,yi,xe,ye;
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) {
			v[i][j] = INT_MAX;
			cin >> c[i][j];
			if(c[i][j] == 'M') { 
				v[i][j] = 0;
				q.push(make_pair(i,j));
			}
			if(c[i][j] == 'S')
				xi = i, yi = j;
			if(c[i][j] == 'F')
				xe = i, ye = j;
		}
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx >= 0 and yy >= 0 and xx < n and yy < m and v[xx][yy] == INT_MAX) {
				q.push(make_pair(xx,yy));
				v[xx][yy] = v[x][y] + 1;
			}
		}
	}
	dis[xi][yi] = 0;
	q.push(make_pair(xi,yi));
	if(v[xi][yi] <= d) goto ans;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(x == xe and ye == y) break;
		for (int i = 0; i < 4; ++i) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx >= 0 and yy >= 0 and xx < n and yy < m and dis[xx][yy] == -1 and v[xx][yy] > d) {
				q.push(make_pair(xx,yy));
				dis[xx][yy] = dis[x][y] + 1;
				if(xx == xe and yy == ye) goto ans;
			}
		}
	}
	
	ans:
	
	cout << dis[xe][ye] << "\n";
	return 0;
}
