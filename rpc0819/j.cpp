#include <bits/stdc++.h>

using namespace std;

int a[10];
bool vis[1010];
int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    int target;
    cin >> target;
    int ans = 1e9;
    for (int i = 0; i < 10; ++i) 
        for (int j = 0; j < 10; ++j) 
            for (int k = 0; k < 10; ++k) {
                if(a[i] or a[j] or a[k]) continue;
                int val = i * 100 + j * 10 + k;
                int v1 = i * 10 + j;
                int v2 = j;
                ans = min(ans, abs(val - target));
                ans = min(ans, abs(v1 - target));
                ans = min(ans, abs(v2 - target));
            }
    
    cout << ans << "\n";
    return 0;
}

