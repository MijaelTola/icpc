#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>
#include <string> 
#include <sstream>
#include <cstdlib>

using namespace std;

typedef long long ll;

map<string,int> id;
vector<int> G[30100],G2[30100];
set<pair<int,int> >bridges;
queue<int> q;
int nc[30100];
int dis[30100];
int low [30100];
int num[30100];
int parent[30100];
int scc[30100];
int nscc;

void findBridges(int u){
	low[u] = num[u] = nscc++;
	for (int i = 0; i < (int)G[u].size(); ++i){
		int v = G[u][i];
		if(num[v] == -1){
			parent[v] = u;
			findBridges(v);
			if(low[v] > num[u]){
				bridges.insert(make_pair(min(u,v),max(u,v)));
			} 
			low[u] = min(low[u],low[v]);
		}else if(v != parent[u]) low[u] = min(low[u],num[v]);
	}
}

void paint(int u,int color){
    nc[color]++;
    for (int i = 0; i < (int)G[u].size();++i){
		int v = G[u][i];
		int mn = min(u,v);
		int mx = max(u,v);
		if(!bridges.count(make_pair(mn,mx))){
			if(scc[v] ==-1){
			scc[v] = color;
			paint(v,color);
			}
		}
	}
}

void clean(){
    for (int i = 0; i < 30100; ++i){
        G[i].clear();
        G2[i].clear();
        low[i] = 0;
        num[i] = -1;
        parent[i] = 0;
        scc[i] = -1;
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        
        clean();
        int c = 0;
        int m; cin >> m;
        for (int i = 0; i < m; ++i){
            string x,y;
            cin >> x >> y;
            if(!id.count(x)) id[x] = c++; 
            if(!id.count(y)) id[y] = c++;
            G[id[x]].push_back(id[y]);
            G[id[y]].push_back(id[x]);
        }
    
        nscc = 0;
        for (int i = 0; i < (int)id.size(); ++i)
            if(num[i] == -1)findBridges(i);
        int col = 0;
        for (int i = 0; i < (int)id.size(); ++i){
            if(scc[i] == -1){
                ++col;
                scc[i] = col;
                paint(i,col);
            }
        }
        //for (int i = 0; i < (int)id.size(); ++i) cout << i << " " << scc[i] << endl;
        for (int i = 0; i < (int)id.size(); ++i){
            for (int j: G[i]){
                if(scc[i] != scc[j]){
                    G2[scc[i]].push_back(scc[j]);
                    G2[scc[j]].push_back(scc[i]);
                }
            }
        }
        //for (int i = 1; i <= col; ++i) cout <<i << " " << nc[i] << endl;
        
    }
    return 0;
}

