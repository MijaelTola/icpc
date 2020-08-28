#include <bits/stdc++.h>

using namespace std;

int n,m,p;
int G[1010][1010];
int toy[1010];
int way[1010];

bool bfs (int x,int y){
	memset(way,-1,sizeof way);
	queue<int> q;
	q.push(x);
	way[x] = x;
	while(!q.empty()){
		int u = q.front();q.pop();
		if(u == y)return true;
		for(int i = 1; i <= n + m + p + 1; i++){
			if(way[i] == -1 and G[u][i] > 0){
				way[i] = u;
				q.push(i);
			}
		}
	}
	return false;
}

int max_flow(int s,int t){
	int ans = 0;
	while(bfs(s,t)){
		int mn = 1e9;
		for(int v = t; v != s; v = way[v]){
			int u = way[v];
			 mn = min(mn,G[u][v]);
		}
		ans += mn;
		for (int v = t; v != s; v = way[v]){
			int u = way[v];
			G[u][v] -= mn;
			G[v][u] += mn;
		}
	}
	return ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> p;
    
    for (int i = 1; i <= n; ++i)
        G[0][i] = 1;
    for (int i = 1; i <= n; ++i){
        int k; cin >> k;
        for (int j = 0; j < k; ++j){
            int x; cin >> x;
            G[i][x + n] = 1e9;
        }
    }
    for (int i = n + m + 1; i <= p + m + n ; ++i){
        int l; cin >> l;
        for (int j = 0; j < l; ++j){
            int x; cin >> x;
            G[x+ n][i] = 1;
            toy[x + n]++;
        }
        int r; cin >> r;
        G[i][n + m + p + 1] = r;
    }
    
    for (int i = n + 1; i <= n + m; ++i)
        if(!toy[i])G[i][n + m + p + 1] = 1;
    
    cout << max_flow(0,n + p + m + 1) << "\n";
    return 0;
}

