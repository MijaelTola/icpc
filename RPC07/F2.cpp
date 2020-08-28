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

ll l;
int a,b,c,d;
int m[5][5010];
int dp[5][100000010];
int v[4];
int f(int row, int sum){
    if(row == 4)return sum <= l;
    if(sum > l) return 0;
    if(dp[row][sum] != -1) return dp[row][sum];
    int ans = 0;
    for (int i = 0; i < v[row]; ++i){
        ans += f(row+1,sum + m[row][i]);
    }
    return dp[row][sum] = ans;
}
int main(){
    
    while(cin >> l){
        memset(dp,-1,sizeof dp);
        for (int i = 0; i < 4; ++i) cin >> v[i];
        if(!l) return 0;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < v[i]; ++j) cin >> m[i][j];
            cout << f(0,0) << endl;
    }


    return 0;
}

