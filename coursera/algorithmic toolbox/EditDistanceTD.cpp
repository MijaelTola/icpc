#include <iostream>
#include <cstring>
using namespace std;

string x,y;
int dp[110][110];
int f(int px,int py){
    if(px == (int)x.size() or py == (int)y.size()) return 0;
    if(dp[px][py] != -1) return dp[px][py];
    int ans = 1e7;  
    if(x[px] == y[py]) ans = min(ans,f(px+1,py+1));
    ans = min(ans,f(px+1,py)+1);
    ans = min(ans,f(px,py+1)+1);
    return dp[px][py] = ans;
}
int main(){
    memset(dp,-1,sizeof dp);
    cin >> x >> y;
    cout << f(0,0) << endl;
    return 0;
}
