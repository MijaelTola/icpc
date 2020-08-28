#include <bits/stdc++.h>

using namespace std;

int b[110];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n) {
        int t = 0;
        for (int i = 0; i < n; ++i)  {
            int x; cin >> x;
            t += x;
        }
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        sort(b, b + n);
        reverse(b, b + n);
        int ans = 0;
        while(t > 0) {
            t -= b[ans];
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}

