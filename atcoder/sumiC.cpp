#include <bits/stdc++.h>

using namespace std;

vector<int> v;
bool dp[200000];
int main() {
    
    for (int i = 100; i <= 105; ++i)
        v.push_back(i);

    int x;
    cin >> x;
    
    dp[x] = 1;

    for (int i = x - 1; i >= 0; --i) 
        for (int z: v) 
            dp[i] |= dp[i + z];

    puts(dp[0] ? "1":"0");
    return 0;
}

