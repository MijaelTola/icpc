#include <iostream>

using namespace std;

char c[110][110];

int dy[] = {1,1,0,-1,-1,-1,0,1};
int dx[] = {0,1,1,1,0,-1,-1,-1};

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n,m;
	int p = 0;
	while(cin >> n >> m and n and m){
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> c[i][j];
		cout << "Field #" << ++p<< ":" << "\n";
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				if(c[i][j] == '*'){
					cout << "*";
					continue;
				}
				int ans = 0;
				for (int k = 0; k < 8; ++k){
					int u = i+dx[k];
					int v = j+dy[k];
					if(u >= 0 and u < n and v >= 0 and v < m){
						if(c[u][v] == '*') ans++;
					}
				}
				cout << ans;
			}
			cout << "\n";
		}
		cout << "\n";
	}
}
