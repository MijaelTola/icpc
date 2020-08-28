#include <bits/stdc++.h>

using namespace std;

int t,n;
int val[30];
int p[40];
vector<int> v;
int main() {
    val['a' - 'a'] = 0;
    val['e' - 'a'] = 1;
    val['i' - 'a'] = 2;
    val['o' - 'a'] = 3;
    val['u' - 'a'] = 4;
    cin >> t;
    while(t--) {
        v.clear();
        memset(p, 0, sizeof p);
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            int cur = 0;
            for (int j = 0; j < (int)s.size(); ++j) {
                int pos = val[s[j] - 'a'];
                cur |= (1 << pos);
            }
            p[cur]++;
            v.push_back(cur);
        }

        long long ans = 0;
        
       
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (1 << 5); ++j) {
                int cur = v[i] | j;
                if(cur == (1 << 5) - 1 and p[j] > 0) {
                    ans += p[j];
                    if(v[i] == j) ans--;
                }
            }
        }
        cout << ans / 2 << "\n";
    }

    return 0;
}

