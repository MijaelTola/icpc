#include <bits/stdc++.h>

using namespace std;

int v[100010];

int main() {
    
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }
    
    sort(v, v + n);
    sum = v[n / 2];

    auto is = [](long long x) {
        if(x == 1 or x == 0) return 0;
        for (int i = 2; i * i <= x; ++i)
            if(x % i == 0) return 0;
        return 1;
    };
    
    auto f = [is](long long x, int cur) {
        while(!is(x)) x += cur;
        return x;
    };
    
    auto solve = [n](long long x) {
        long long ans = 0;
        for (int i = 0; i < n; ++i)
            ans += abs(v[i] - x);
        return ans;
    };
    
    cout << min(solve(f(sum, 1)), min(solve(f(sum - 1, -1)), solve(f(sum + 1, 1)))) << "\n";
    return 0;
}

