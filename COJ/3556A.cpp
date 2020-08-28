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
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
int n;
int v[22];
int r[22][1010];
int dp[22][1010];
int f(int pos, int k){
    if(pos == n) return 0;
    int ans = 0;
    if(dp[pos][k] != -1) return dp[pos][k];
    for (int i = 0; i < v[pos] and i < k; ++i)
        ans = max(ans,f(pos+1,k-i-1)+10*(i+1)-r[pos][i]);
    ans = max(ans,f(pos+1,k));
    return dp[pos][k] = ans;
}

vector<int> q;

void rec(int pos,int k){
    if(pos == n) return;
    int ans = -1;
    int id = -1;
    int sz = 0;
    for (int i = 0; i < v[pos] and i < k; ++i){
        int p = dp[pos+1][k-i-1]+10*(i+1)-r[pos][i];
        if(p > ans){
            ans = p;
            id = k-i-1;
            sz= i;
        }
    }
    int ans2 = dp[pos+1][k];
        
    if(ans > ans2){
        q.push_back(sz+1);
        rec(pos+1,id);
    }else{
        q.push_back(0);
        rec(pos+1,k);
    }
}   
int main(){
    memset(dp,-1,sizeof dp);
    int c;
    cin >> n >> c;

    for (int i = 0; i < n; ++i){
        cin >> v[i];
        for (int j = 0; j < v[i]; ++j){
            cin >> r[i][j];
            if(j > 0) r[i][j] += r[i][j-1];
        }
    }

    int ans = -1;
    int boxes = 0;
    for (int i = 1; i <= c; ++i){
        int x = f(0,i);
        if(x > ans){
            ans = x;
            boxes = i;
        }
    }
    if(!ans){
        cout << "0 0\n";
        for (int i = 0; i < n; ++i) cout << 0 << " ";
    }else{
        cout << ans << " " << boxes << endl;
        rec(0,boxes);
        for (int i = 0; i < (int)q.size(); ++i)
            cout << q[i] << " ";
    }
    return 0;
}

