#include <bits/stdc++.h>

using namespace std;

long long memo[1000000];

long long f(int x) {
    if(x < 2) return x;
    if(memo[x] != -1) return memo[x];
    return memo[x] = f(x - 1) + f(x - 2);
}

long long r(int x) {
    if(x < 2) return x;
    return r(x - 1) + r(x - 2);
}
int main() {
    memset(memo, -1, sizeof memo);
    int x;
    cin >> x;
    cout << f(x) << endl;
    cout << r(x) << endl;
    return 0;
}

