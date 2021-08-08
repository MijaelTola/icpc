#include <bits/stdc++.h>

using namespace std;

long long f[14];
bool vis[26];
int main() {

    f[0] = 1;
    for (int i = 1; i < 14; ++i)
        f[i] = i * f[i - 1];

    int t;
    cin >> t;
    while(t--) {
        memset(vis, 0, sizeof vis);
        long long n;
        cin >> n;

        for (int i = 0, j = 12; i < 13; ++i, j--) {
            vector<int> v;
            for (int i = 0; i < 26; ++i) 
                if(!vis[i]) v.push_back(i);
            
            long long current = 0;
            int cnt = 0;
            while(current + f[j] < n) {
                current += f[j];
                cnt++;
            }
            n -= current;
            cout << (char)(v[cnt] + 'a');
            vis[v[cnt]] = 1;
        }
        cout << "\n";

    }
    return 0;
}

