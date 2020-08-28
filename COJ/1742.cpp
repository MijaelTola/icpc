	#include <iostream>
	#include <vector>
	#include <stack>
	
	using namespace std;
	
	vector<int> G[2010];
	vector<int> GC[2010];
	int scc[2010];
	bool vis[2010];
	stack<int> s;
	int n;
	void dfs(int u){
		for (int x: G[u]){
			if(!vis[x]){
				vis[x] = true;
				dfs(x);
			}
		}
		s.push(u);
	}
	void dfs2(int u,int num){
		//cout << u << endl;
        for (int x: GC[u]){
			if(scc[x] == -1){
				scc[x] = num;
				dfs2(x,num);
			}
		}
	}
	
	void clean(){
		for (int i = 0; i < 2010; ++i){
			vis[i] = false;
			scc[i] = -1;
			G[i].clear();
			GC[i].clear();
		}
	}
	int kosaraju(){
		for (int i = 1; i <= n; ++i){
			if(!vis[i]){
				vis[i] = true;
				dfs(i);
			} 
		}
		int color = 0;
		while(!s.empty()){
            //cout << s.top() << endl;
			int u = s.top(); s.pop();
			if(scc[u] == -1){
				scc[u] = ++color;
				dfs2(u,color);
			}
		}
		return color;
	}
	
	int main(){
		ios::sync_with_stdio(false); cin.tie(0);
		int m;
		while(cin >> n >> m and n and m){
			clean();
			
			for (int i = 0; i < m; ++i){
				int x,y; 
				cin >> x >> y;
				G[x].push_back(y);
				GC[y].push_back(x);
			}
		    cout << kosaraju() << endl;
			
		}
		return 0;
	}
	
