#include <bits/stdc++.h>

using namespace std;

long long v[200001];
long long b[200001];
set<long long> s;
int main() {
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    for (int i = n - 1; i >= 0; i--) 
        b[i] = v[i] + b[i + 1];

    for (int i = 0; i < n; ++i)
        s.insert(b[i]);
    
    long long sum = 0;
    
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        s.erase(b[i]);
        sum += v[i];
        if(s.count(sum))
            ans = max(ans, sum);
    }

    cout << ans << "\n";

    return 0;
}

