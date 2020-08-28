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

using namespace std;

typedef long long ll;

vector<int> G[10010];
int match[10010];
int vis[10010];
int Aug(int l){
    if(vis[l]) return false;
    vis[l] = true;
    for (int j: G[l]){
        if(match[j] == -1 or Aug(match[j])){
            match[j] = l; return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    while(cin >> n >> m and n and m){
        for (int i = 0; i < 10010; ++i) G[i].clear();
        for (int i = 0; i < m; ++i){
            int x,y; cin >> x >> y; 
            G[x].push_back(y);
          //  G[y].push_back(x);
        }
        memset(match,-1,sizeof match);
        int mcbm = 0;
        for (int i = 0; i < n; ++i){
            memset(vis,false,sizeof vis);
            mcbm += Aug(i);
        }
        cout << mcbm << "\n";
    }
    return 0;
}

