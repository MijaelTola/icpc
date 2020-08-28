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

int n,m;
vector<int> v[310];
int dp[310][310];
int f(int x, int total){
    if(x == n){
        if(total >= n) return 0;
        return 1e9;
    }
    if(dp[x][total] != -1) return dp[x][total];
    int cost = 0;
    int ans = 1e9;
    for (int i = 0; i < (int)v[x].size(); ++i){
        cost += v[x][i];
        ans = min(ans,f(x+1,total+i+1)+cost+((i+1)*(i+1)));
    }
    ans = min(ans,f(x+1,total));
    return dp[x][total] = ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);   
    int t; cin >> t;
    for (int k = 1; k <= t; ++k){
        cin >> n >> m;
        memset(dp,-1,sizeof dp);
        for (int i = 0; i < 310; ++i) v[i].clear();
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                int x; cin >> x;
                v[i].push_back(x);
            }
            sort(v[i].begin(),v[i].end());
        }
        cout << "Case #" << k << ": " << f(0,0) << "\n";
    }
    return 0;
}

