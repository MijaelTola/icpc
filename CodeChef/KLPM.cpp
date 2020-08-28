#include <bits/stdc++.h>

using namespace std;

const long long p = 9999999900000001LL;
const long long x = 909091;
int n;
string s;
int main() {
    cin >> s;
    n = s.size();

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        long long hash = 0;
        string test = "";
        for (int j = i; j < n; ++j) {
            test += s[j];
            for (int l = 0; l < n; ++l) {
                string test1 = test;
                for (int k = l; k < n; ++k) {
                    if((i <= l and l <= j) or (i <= k and k <= j)) break;
                   
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

