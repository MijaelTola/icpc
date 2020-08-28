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
vector<int> G[33100];
bool vis[33100];
bool mark[33100];

int bfs(int i){
	memset(vis,false,sizeof vis);
	queue<pair<int,int> > q;
	q.push({i,0});
	int ans = 0;
	bool flag = false;
	while(!q.empty()){
		int u = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int v: G[u]){
			if(!vis[v] and !mark[v]){
				vis[v] = true;
				if(c+1 > 5){
					flag = true;
					mark[v] = true;
					ans++;
				}else q.push({v,c+1});
			}
		}
	}
	if(flag){
		ans++;
		mark[i] = true;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--){
		memset(mark,false,sizeof mark);
		int m; cin >> m;
		int c = 0;
        for (int i = 0; i < m; ++i){
            string x,y;
            cin >> x >> y;
            if(!id.count(x)) id[x] = c++; 
            if(!id.count(y)) id[y] = c++;
            G[id[x]].push_back(id[y]);
            G[id[y]].push_back(id[x]);
        }
        int ans = 0;
        for (int i = 0; i < (int)id.size(); ++i){
			if(!mark[i]){
				ans += bfs(i);
			}
		}
		int total = id.size();
		if(total*0.05 > ans) cout <<  "YES" << "\n";
		else cout << "NO" << "\n";
	}
    return 0;
}

