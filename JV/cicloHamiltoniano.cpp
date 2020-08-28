#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 25

bool dp[MAXN][1<<MAXN];
int adj[MAXN][MAXN];

bool check_using_dp(int n){
		memset(dp,false,sizeof dp);
        for(int i=0; i<n; i++)
            dp[i][1<<i]=true;
        
        for(int i=0; i<(1<<n); i++){
            for(int j=0; j<n; j++)
                if(i&(1<<j)){
                    for(int k=0; k<n; k++)
                        if(i&(1<<k) and adj[k][j] and k!=j and dp[k][i^(1<<j)]){
                            dp[j][i]=true;
                            break;
                        }
                }
        }
        
        for(int i=0; i<n; i++)
            if(dp[i][(1<<n)-1])
                return true;
        return false;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
	int n,m;
	while(cin >> n >> m){
		memset(adj,0,sizeof adj);
		for (int i = 0; i < m; ++i){
			int x,y; cin >> x >> y;
			adj[x][y] = 1;
			adj[y][x] = 1;
		}
		cout << check_using_dp(n) << "\n";
	}
    return 0;
}
