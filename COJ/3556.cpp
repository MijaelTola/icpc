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

typedef long long ll;
int a,m;
pair<int,int> dp[20][1210][1010];
int p[22][1010];
int v[22];
vector<int> q;
pair<int,int> f(int r, int c, int t){
    if(r == a or t == 0) return {0,0};
    if(c == v[r]) return {0,0};
    
    if(dp[r][c][t].first != -1) return dp[r][c][t];
    
    pair<int,int> ans = {0,0};
    pair<int,int> x = f(r,c+1,t-1);
    
    x.first += 10-p[r][c]; x.second++;
    if(x.first > ans.first) ans = x;
    else if(x.first == ans.first and x.second < ans.second and t-1 >= 0) ans = x;
    
    pair<int,int> e = f(r+1,0,t);
    if(e.first > ans.first) ans = e;
    else if(e.first == ans.first and e.second < ans.second) ans = e;
    
    return dp[r][c][t] = ans;
}
void rec(int r,int c,int t){
    if(r == a or t == 0) return;
    if(c == v[r]) return;

    pair<int,int> x = dp[r][c+1][t-1];
    x.first += 10-p[r][c]; x.second++;
    
    pair<int,int> e = dp[r+1][0][t];
    if(x.first > e.first and t-1 >= 0){
        q.push_back(c);
        rec(r,c+1,t-1);
    }else if(x.first == e.first and x.first < e.first and t-1 >= 0){
        q.push_back(c);
        rec(r,c+1,t-1);
    }else rec(r+1,0,t);
}
int main(){
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < 1210; ++j)
            for (int k = 0; k < 1010; ++k){
                dp[i][j][k].first = -1;
                dp[i][j][k].second = -1;
            }
    cin >> a >> m;
    for (int i = 0; i < a; ++i){
        cin >> v[i];
        for (int j = 0; j < v[i]; ++j) cin >> p[i][j];
    }
    pair<int,int> ans = f(0,0,m);
    cout << ans.first<<" " << ans.second << endl;
    rec(0,0,m);
    for (int i = 0; i < (int)q.size(); ++i)
        cout << q[i] << " ";
    return 0;
}

