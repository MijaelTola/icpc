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


int dp[5000100];

int f(long long x){
    if(x == 1) return 0;
    if(x <= 5000010 and dp[x] != -1) return dp[x];
    int ans = 0;
    if(x&1) ans += f(x * 3 + 1) + 1;
    else ans += f(x / 2) + 1;
    if(x < 5000100) dp[x] = ans;
    return ans;
}

int s(long long x){
    int ans = 0;
    while(x > 1){
        if(x & 1) x = 3 * x + 1;
        else x = x / 2;
        ans++;
    }
    return ans;
}
int v[5000100];
int a[5000100];
int main(){
    memset(dp,-1,sizeof dp);
    for (int i = 1; i < 5000010; ++i) v[i] = f(i);
    int cur = 0;
    for (int i = 1; i < 5000010; ++i){
        if(v[i] >= v[cur]) cur = i;
        a[i] = cur;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int x;
        scanf("%d",&x);
        printf("%d\n",a[x]);
    }
    return 0;
}

