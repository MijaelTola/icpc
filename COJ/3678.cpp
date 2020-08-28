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

int parent[10010];
int rnk[10010];
int color[10010];
void init(){
    for (int i = 0; i < 10010; ++i){
        parent[i] = i;
        rnk[i] = 0;
        color[i] = -1;
    }
}

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y){
    int px = find(x);
    int py = find(y);
    if(rnk[px] > rnk[py]) parent[py] = px;
    else{
        parent[px] = py;
        if(rnk[px] == rnk[py]) rnk[py]++;
    }
}
bool verify(int x, int y){
    return color[x] == -1 or color[y] == -1; 
}
int main(){
    //ios::sync_with_stdio(false); cin.tie(0);
    int n,q;
    while(cin >> n >> q){
        init();
        while(q--){
            int c,x,y;
            cin >> c >> x >> y;
            if(c == 1){
                if((color[x] == -1 or color[y] == -1) or (color[x] == color[y])){
                    if(find(x) != find(y)){
                        Union(x,y);
                        color[x] = 1;
                        color[y] = 1;
                    }
                }else cout << -1 << "\n";
            }
            if(c == 2){
                if(color[x] == -1 or color[y] == -1 or (color[x] == 2 and color[y] == 2)){
                    if(find(x) != find(y)){
                        Union(x,y);
                        color[x] = 2;
                        color[y] = 2;
                    }
                }else cout << -1 << "\n";
            }
            if(c == 3){
                if(color[x] == 1 and 1 == color[y])cout << 1 << "\n";
                else cout << 0 << endl;
            }
            if(c == 4){
                if(color[x]==2 and 2 == color[y]) cout << 1 << "\n";
                else cout << 0 << endl;
            }

        }
    }
    return 0;
}

