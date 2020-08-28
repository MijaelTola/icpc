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

const int mod = 1e9+7;
int dp[510][510];
int f(int n, int m){
    if(n < 0 or m < 0) return 0;
    if(n == 1 and m == 1) return 1;
    if(dp[n][m] != -1) return dp[n][m];
    int ans = 0;
    ans = (ans + f(n-1,m)) % mod;
    ans = (ans + f(n,m-1)) % mod;
    return dp[n][m] = ans;
}
int main(){
    memset(dp,-1,sizeof dp);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        printf("%d\n",f(n+1,m+1));
    }
    return 0;
}

