#include <bits/stdc++.h>

using namespace std;

long long v[100010];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    long long s;
    while(cin >> n >> s) {
        for (int i = 0; i < n; ++i) 
            cin >> v[i];

        for (int i = 1; i < n; ++i)
            v[i] += v[i - 1];

        int a = 0, b = 0;
        int ans1 = -1, ans2 = -1;
        while(a < n and b < n) {
            long long sum = v[b];
            if(a) sum -= v[a - 1];
            if(sum == s) {
                ans1 = a + 1;
                ans2 = b + 1;
                break;
            }
            if(sum >= s) a++;
            else b++;
        }
        if(ans1 == -1) cout << "-1\n";
        else cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}

