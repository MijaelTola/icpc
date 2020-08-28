#include <bits/stdc++.h>

using namespace std;

int t,n;
string k;
int v[100010];
int b[100010];

int main() {
    cin >> t;
    while(t--) {
        memset(v, 0, sizeof v);
        memset(b, 0, sizeof b);
        cin >> n >> k;
        int cur = 0;
        for (int i = 0; i < (int)k.size(); ++i) {
            cur = cur * 10;
            cur += (int)(k[i] - '0');
            cur %= n;
        }

        int a = cur;
        for (int i = 0; i < n; ++i) {
            if(i % 2 != 0 and a) {
                v[i] = 1;
                a--;
            }
        }

        int pos = n - 1;
        while(pos >= 0 and a) {
            if(v[pos] == 0) a--,v[pos] = 1;
            pos--;
        }
        a = cur;

        for (int i = 0; i < n; ++i) {
            if(i % 2 == 0 and a) {
                b[i] = 1;
                a--;
            }
        }

        pos = n - 1;
        while(pos >= 0 and a) {
            if(b[pos] == 0) a--,b[pos] = 1;
            pos--;
        }
        int ans = 0, ans2 = 0;
        for (int i = 0; i < n - 1; ++i) {
            ans += abs(v[i] - v[i + 1]);
            ans2 += abs(b[i] - b[i + 1]);
        }

        cout << max(ans, ans2) << "\n";
    }

    return 0;

}



