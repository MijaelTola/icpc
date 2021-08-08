#include <bits/stdc++.h>

using namespace std;

int n;
int lim;
int sum;
vector<int> v;
int dp[101][100001];

int f(int pos, int s) {
    if(pos == n) {
        int b = sum - s;
        if(max(s, b) <= lim) return 1;
        return 0;
    }
    
    int &ans = dp[pos][s];
    if(ans != -1) return ans;
    ans = 0;
    ans |= f(pos + 1, s);
    ans |= f(pos + 1, s + v[pos]);
    return ans;
}

int main() {
    
    cin >> n;
    
    sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
        v.push_back(x);
    }

    
    sort(v.rbegin(), v.rend());
    
  
    int a = -1, b = 1e5;

    while(b - a > 1) {
        memset(dp, -1, sizeof dp);
        int mid = (a + b) / 2;
        lim = mid;
        if(f(0, 0)) b = mid;
        else a = mid;
    }

    cout << b << "\n";
    return 0;
}

