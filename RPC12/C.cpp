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
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;

int n,m;
int need[50010];
int actual[50010];
bool vis[50010];
bool tr[50010];
vector<int> G[50010];
set<int> s;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < 50010; ++i) need[i] =1;
    memset(vis,false,sizeof vis);
    cin >> n >> m;

    for (int i = 0; i < m; ++i){
        int x,y; cin >> x >> y;
        G[x].push_back(y);
    }
    
    
    for (int i = 1; i <= n; ++i){
        for (int j: G[i]){
            need[j]++;
        }
    }
    for (int i = 1; i <= n; ++i) cout << need[i] << " ";
    cout << endl;
    memset(vis,false,sizeof vis);
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        if(!vis[x]){
            memset(tr,false,sizeof tr);
            actual[x]++;
            queue<int> q;
            q.push(x);
            while(!q.empty()){
                int u = q.front(); q.pop();
                if(need[u] == actual[u]) s.insert(u);
                for (int v: G[u]){
                    if(!tr[v]){
                        tr[v] = true;
                        actual[v]++;
                        q.push(v);
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i) cout << actual[i] << " ";
        cout << s.size() << "\n";
    }
    return 0;
}

