#include <bits/stdc++.h>

using namespace std;

int n;
unordered_map<char,int> mp2;
bool cards[5][5];

int main() {

    mp2['R'] = 0;
    mp2['G'] = 1;
    mp2['B'] = 2;
    mp2['Y'] = 3;
    mp2['W'] = 4;
    int cur = 0;
    string s;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> s;
        int c = mp2[s[0]];
        int v = s[1]-'1';
        cards[c][v] = true;
    }

    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            if(cards[i][j]) {
                cur++;
            }
        }
    }

    int ans = 11;

    for(int i = 0; i < (1 << 5); ++i) {
        for(int j = 0; j < (1 << 5); ++j) {
            int current = 0;
            int bits = __builtin_popcount(i) + __builtin_popcount(j);
            int aa[5], bb[5];
            for(int i = 0; i < 5; ++i) {
                aa[i] = bb[i] = 0;
            }
            for(int m = 0; m < 5; ++m) {
                for(int n = 0; n < 5; ++n) {
                    if(cards[m][n]) {
                        aa[n]++;
                        bb[m]++;
                    }
                }
            }
            for(int m = 0; m < 5; ++m) {
                for(int n = 0; n < 5; ++n) {
                    if(cards[m][n] && (i & (1<<m)) && (j & (1<<n))) {
                        aa[n]--;
                        bb[m]--;
                    }
                }
            }
            for(int m = 0; m < 5; ++m) {
                for(int n = 0; n < 5; ++n) {
                    if(cards[m][n]) {
                        if((i & (1<<m)) && (j & (1<<n))) {
                            current++;
                        } else if((i & (1<<m)) && bb[m] == 1) {
                            current++;
                        } else if((j & (1<<n)) && aa[n] == 1) {
                            current++;
                        }
                    }
                }
            }

            if(current + 1 >= cur)
                ans = min(ans, bits);
        }
    }
    cout << ans << "\n";
    return 0;
}
