#include <bits/stdc++.h>

using namespace std;

int n;
int v[100010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        
        long long sum = 0;
        long long mx = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            sum += (v[i] - 1);
        }
        
        cout << sum + 1 << "\n";
        
        
    }
    return 0;
}

