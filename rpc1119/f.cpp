#include <bits/stdc++.h>

using namespace std;

string s;
int sz;
string g = "meow";
int dp[1000010][4];
int f(int pos, int cur) {
    if(pos == sz) {
        if(cur == 4) return 0;
        return 1e9;
    }
    if(cur == 4) return 0;
    int &ans = dp[pos][cur];
    if(ans != -1) return ans;
    ans = 1e9;

    if(s[pos] == g[cur]) 
        ans = min(ans, f(pos + 1, cur + 1));
    
    //1
    ans = min(ans, f(pos, cur + 1) + 1);
    //2
    ans = min(ans, f(pos + 1, cur) + 1);
    //3
    ans = min(ans, f(pos + 1, cur + 1) + 1);
    //
    ans = min(ans, f(pos + 2, cur + 1));

    ans = min(ans, f(pos + 1, 0));
    return ans;
}
int main() {

    cin >> s;
    
    cout << f(0, 0) << "\n";
    return 0;
}

