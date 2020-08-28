#include <bits/stdc++.h>

using namespace std;

int dp[100010][110];
struct Solution {

    int na,nb;
    string sa, sb; 
    int f(int pa, int pb) {
        if(na == pa or nb == pb) return 0;
        int &ans = dp[pa][pb];
        if(ans != -1) return ans;
        ans = max(ans, f(pa + 1, pb));
        if(sa[pa] == sb[pb]) 
            ans = max(ans, f(pa + 1, pb + 1) + 1);
        return ans;
    }

    int minimunConcat(string initial, string goal) {
        memset(dp, -1, sizeof dp);   
        sa = initial;
        sb = goal;
        na = initial.size();
        nb = goal.size();
        
        int pos = 0;
        int ans = 0;
        while(pos < nb) {
            pos += f(0, pos);
            ans++;
        }
        return ans;
    }
};
int main() {
    Solution s;
    string a,b;
    while(cin >> a >> b) {
        cout << s.minimunConcat(a,b) << " fin\n";
    }
    return 0;
}

