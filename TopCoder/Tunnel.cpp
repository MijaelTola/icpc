#include <bits/stdc++.h>

using namespace std;

class Tunnel {
public:
	int minKeystrokes(vector <string>, int);
};

int n,rt;
vector<string> v;

int dp[55][55];
int f(int pos, int cur) {
    if(pos == n) return 0;
    int &ans = dp[pos][cur];
    if(ans != -1) return ans;
    ans = 1e9;
    for (int i = 0, x = cur; i <= rt and x < (int)v[pos].size(); ++i, x++) 
        if((pos + 1 == n or v[pos + 1][x] != '#') and v[pos][x] != '#') ans = min(ans, f(pos + 1, x) + i);
    
    for (int i = 0, x = cur; i <= rt and x >= 0; ++i, x--) 
        if((pos + 1 == n or v[pos + 1][x] != '#') and v[pos][x] != '#') ans = min(ans, f(pos + 1, x) + i);
    return ans;

}
int Tunnel::minKeystrokes(vector <string> level, int rate) {
	v = level;
    n = level.size();
    rt = rate;
    int ini = -1;
    for (int i = 0; i < (int)v[0].size(); ++i)
        if(v[0][i] == 'v') {
            ini = i;
            break;
        }
      
    memset(dp, -1, sizeof dp);
    int ans = f(0,ini);
    if(ans < 1e9) return ans;
    return -1;
}




//Powered by [KawigiEdit] 2.0!
