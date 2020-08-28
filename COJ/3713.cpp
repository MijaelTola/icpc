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

int n,m,p;
struct grid{
    int x,y,t,p;
    grid(){}
    grid(int xx, int yy, int tt, int pp){
        x = xx; y = yy; t = tt; p = pp;        
    }
    bool operator < (const grid &g){
        return t < g.t;
    }
};

vector<grid> v;
bool cmp(const grid A, const grid B){
    return A.t < B.t;
}
int manhattan(int x,int y,int a,int b){
    return abs(x-a)+abs(y-b);
}
int dp[10010];
int f(int pos){
    if(dp[pos] != -1) return dp[pos];
    int ans = 0;
    for (int i = pos+1; i < (int)v.size(); ++i){
        int time = manhattan(v[pos].x,v[pos].y,v[i].x,v[i].y);
        if(time+v[pos].t <= v[i].t) ans = max(ans,f(i)+v[i].p);
    }
    return dp[pos] = ans;
}
int main(){
    int t; cin >> t;
    while(t--){
        memset(dp,-1,sizeof dp);
        v.clear();
        cin >> n >> m >> p;
        int xi,yi;
        cin >> xi >> yi;
        v.push_back(grid(xi,yi,0,0));
        for (int i = 0; i < p; ++i){
            int x,y,t,p;
            cin >> x >> y >> t >> p;
            v.push_back(grid(x,y,t,p));
        }
        sort(v.begin(),v.end(),cmp);
        cout << f(0) << endl;
    }
    return 0;
}

