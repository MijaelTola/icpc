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

int parent[100010];
int link[100010];
int data[100010];
void init(){
    for (int i = 0; i < 100010; ++i) parent[i] = i;
}
int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int ans;
void Union(int x, int y){
    int px = find(x);
    int py = find(y);
    data[px] += data[py];
    ans = max(ans,data[px]);
    parent[py] = px;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m; cin >> n >> m;
    init();
    for (int i = 1; i <= n; ++i){ cin >> data[i]; ans = max(ans,data[i]);}
    while(m--){
        int x,y; cin >> x >> y;
        if(find(x) != find(y)) Union(x,y);
        cout << ans << "\n";
    }
    return 0;
}

