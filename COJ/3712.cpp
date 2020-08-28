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

int c[310][310];
int dp[310][310];
int n,m;

int f(int x,int y){
    if(x >= n) return f(0,y+2);
    if(y >= m) return 0;
    if(dp[x][y] != -1) return dp[x][y];
    int ans = -1;
    if(x == 0) ans = max(ans,f(0,y+1));
    ans = max(ans,f(x+2,y)+c[x][y]);
    ans = max(ans,f(x+1,y));
    return dp[x][y] = ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> m){
        memset(dp,-1,sizeof dp);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> c[i][j];
        cout << f(0,0) << "\n";
    }
    return 0;
}

