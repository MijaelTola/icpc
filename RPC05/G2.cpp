#include <iostream>
#include <cstring>

using namespace std;

int grid[25][25][1010];
int dp[25][25][1010];
int n,m,p,tmax;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int f(int x,int y,int time){
	if(time == tmax) return 0;
	if(dp[x][y][time] != -1) return dp[x][y][time];
	int ans = -1;
	for (int i = 0; i < 4; ++i){
		int u = dx[i] + x;
		int v = dy[i] + y;
		if(u >= 1 and u <= n and v >= 1 and v <= m)
			ans = max(ans,f(u,v,time+1)+grid[x][y][time]);
	}
	ans = max(ans,f(x,y,time+1)+grid[x][y][time]);
	return dp[x][y][time] = ans;
}

void clean(){
	for (int i = 0; i < 25; ++i)
		for (int j = 0; j < 25; ++j)
			for (int z = 0; z < 1010; ++z){
				dp[i][j][z] = -1;
				grid[i][j][z] = 0;
			}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--){
		clean();
		cin >> n >> m >> p;
		int xc,yc;
		cin >> xc >> yc;
		tmax = -1;
		for (int i = 0; i < p; ++i){
			int x,y,t,f;
			cin >> x >> y >> t >> f;
			grid[x][y][t] = f;
			tmax = max(t,tmax);
		}
		cout << f(xc,yc,0) << "\n";
	}
	return 0;
}
