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

long long dp[21][21];
long long f(int k,int n){
    if(k == 0) return n;
    if(dp[k][n] != -1) return dp[k][n];
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += f(k-1,i);
    return dp[k][n] = ans;
}
int read_input()
{
    int _integer=0;
    char _char=0;
    while(_char<48)
        _char=getchar_unlocked();
    while(_char>=48)
    {
        _integer=10*_integer+_char-48;
        _char=getchar_unlocked();
    }
    return _integer;
}
int main(){
    int k,n; memset(dp,-1,sizeof dp); f(20,20); while(cin >> k >> n) cout << dp[k][n] << "\n";
    return 0;
}

