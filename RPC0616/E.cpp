#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> G[110];
long long tim[15][110];

int n,m,s,t;
int main(){
	memset(tim,0,sizeof tim);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> s >> t;
	
	for (int i = 0; i < m; ++i){
		int x,y; cin >> x >> y;
		G[x].push_back(y);	
		G[y].push_back(x);
	}
	tim[0][s] = 1;
	for (int i = 0; i < t; ++i){
		for (int j = 0; j < n; ++j){
			if(tim[i][j] != 0){
				for (int u: G[j])
					tim[i+1][u] += tim[i][j];
			}
		}	
	}
	long long  ans = 0;
	for (int i = 0; i < n; ++i)
		ans += tim[t][i];
	cout << ans << "\n";
	return 0;
}
