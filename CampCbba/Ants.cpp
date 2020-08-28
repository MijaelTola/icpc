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

bool vis[2*100100];
ll dis[2*100100];
int L[2*100100];
int E[5*100100];
int h[2*100100];
int table[2*100100][100100];
vector<pair<int,ll> > G[100100];

void dfs(int cur,int depth, ll )

int main(){
    memset(vis,false,sizeof vis);
    int n; cin >> n;

    for (int i = 0; i < n-1;++i){
        int x; ll w;
        cin >> x >> w;
        G[i].push_back({x,w});
        G[x].push_back({i,w});
    }
    return 0;
}

