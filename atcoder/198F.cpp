#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;
int s;

int dp[7][1000];
int f(int pos, int sum) {
    if(pos == 6) return sum == s;

    if(sum > s) return 0;

    int ans = 0;
    for (int i = 1; i < 100; ++i)
        ans += f(pos + 1, sum + i);
    return ans;
        
}
int main() {

    while(cin >> s)
    cout << f(0,0) << "\n";
    return 0;
}

