#include <bits/stdc++.h>

using namespace std;

int n,k;
string s;
long long modpow[1000010];
const int mod = 1e9+7;

void init() {
    int p = 1;
    for (int i = 0; i <= 1000000; ++i) {
        modpow[i] = p;
        p = (p * 2) % mod;
    }
}
int main() {
    init();
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k >> s;
        long long ans = 0;

        int pos = 0;

        while(pos < n - 1) {
            queue<int> q;
            int a = 0, b = 0;
            for (int i = pos; i < pos + k + 1 and i < n; ++i) {
                if(s[i] == 'A') a++;
                else b++, q.push(i + 1);
                while(a + k < b and !q.empty()) {
                    cout << q.front() << ": " << a << " " << b << " lol\n";
                    a++,b--, ans += modpow[q.front()], ans %= mod, q.pop();
                }
            }
            pos += k;
        }
        cout << ans << "\n";

    }
    return 0;
}

