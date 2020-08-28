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

int n;
string x;
int dp[100010][4][4][4][4];
int ac[4];
int get(int a, int b, int c){
    ac[0] = ac[1] = ac[2] = ac[3] = 0;
    ac[a] = 1; ac[b] = 1; ac[c] = 1;
    return ac[1]+ac[2]+ac[3];
}
int g(char x){
    if(x == 'M') return 1;
    if(x == 'F') return 2;
    return 3;
}
int f(int pos, int m1, int m2, int m3, int m4){
    if(pos == n) return 0;
    if(dp[pos][m1][m2][m3][m4] != -1) return dp[pos][m1][m2][m3][m4];
    int ans = 0;
    ans = max(ans,f(pos+1,m2,g(x[pos]),m3,m4) + get(g(x[pos]),m1,m2));
    ans = max(ans,f(pos+1,m1,m2,m4,g(x[pos])) + get(g(x[pos]),m3,m4));
    return dp[pos][m1][m2][m3][m4] = ans;
}
int main(){
    memset(dp,-1,sizeof dp);
    cin >> n >> x;
    cout << f(0,0,0,0,0) << endl;
    return 0;
}

