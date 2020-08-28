#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[110][110][110];
vector<long long> x,y,z;
int dx,dy,dz;
int f(int px, int py, int pz){
    if(px == dx or py == dy or pz == dz) return 0;
    int ans = -1;
    if(dp[px][py][pz] != -1) return dp[px][py][pz];
    if(x[px] == y[py] and y[py] == z[pz]) ans =  max(ans,f(px+1,py+1,pz+1)+1);
    ans = max(ans,f(px+1,py,pz));
    ans = max(ans,f(px,py+1,pz));
    ans = max(ans,f(px,py,pz+1));
    return dp[px][py][pz] = ans;
}
int main(){
    cin >> dx;
    for (int i = 0; i < dx; ++i){
        long long p; cin >> p;
        x.push_back(p);
    }
    cin >> dy;
    for (int i = 0; i < dy; ++i){
        long long p; cin >> p;
        y.push_back(p);
    }
    cin >> dz;

    for (int i = 0; i < dz; ++i){
        long long p; cin >> p;
        z.push_back(p);
    }
    memset(dp,-1,sizeof dp);
    cout << f(0,0,0) << endl;
    /* memset(dp,1,sizeof dp);
    for (int i = 1; i <= (int)x.size(); ++i){
        for (int j = 1; j <=(int) y.size(); ++j){
            for (int k = 1; k <= (int)z.size(); ++k){
                if(x[i] == y[j] and y[j] == z[k])
                    dp[i][j][k] = dp[i-1][j-1][k-1]+1;
                else{
                    int ans = -1;
                    ans = max(ans,dp[i-1][j][k]);
                    ans = max(ans,dp[i][j-1][k]);
                    ans = max(ans,dp[i][j][k-1]);
                }
            }
        }
    }
    cout << dp[x.size()-1][y.size()-1][z.size()-1];*/
    return 0;
}
