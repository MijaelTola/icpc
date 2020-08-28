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

using namespace std;

typedef long long ll;
int n;
int v[100010];
int dp[100010];
int f(int pos, int weight){
    if(pos == n) return 0;
    if(dp[pos] != -1) return dp[pos];
    int ans = -1;
    if(weight - v[pos] >= 0) ans = max(ans,f(pos+1, weight - v[pos])+1);
    ans = max(ans,f(pos+1,weight));
    return dp[pos] = ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    long long  w;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> w;
        for (int i = 0; i < n; ++i) cin >> v[i];
        sort(v,v+n);
        int i;
        for (i = 0; i < n and w > 0; ++i)
            if(w - v[i] >= 0) w -= v[i];
            else break;
        cout << i << "\n";
    }
    return 0;
}

