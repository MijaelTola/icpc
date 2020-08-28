#include <bits/stdc++.h>

using namespace std;

int m1[1010][1010];
int m2[1010][1010];
int dm1[12010][12010];
int dm2[12010][12010];
bool isH[12010];
bool isV[12010];
bool isH2[12010];
bool isV2[12010];
string s; 

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        memset(dm1, -1, sizeof dm1);
        memset(dm2, 0, sizeof dm2);
        memset(isH, 0, sizeof isH);
        memset(isV, 0, sizeof isV);
        memset(isH2, 0, sizeof isH2);
        memset(isV2, 0, sizeof isV2);
        int h1,w1,h2,w2;
        cin >> h1 >> w1 >> s;

        for (int i = 1; i <= h1; ++i) 
            for (int j = 1; j <= w1; ++j) {
                int x = s[((i - 1) * w1 + j) - 1] - '0';
                m1[i][j] = x;
            }

        cin >> h2 >> w2 >> s;

        for (int i = 1; i <= h2; ++i) 
            for (int j = 1; j <= w2; ++j) {
                int x = s[((i - 1) * w2 + j) - 1] - '0';
                m2[i][j] = x;
            }

        int a = (h1 * h2) / __gcd(h1,h2);
        int b = (w1 * w2) / __gcd(w1,w2);

        int dh1 = a / h1;
        int dw1 = b / w1;

        for (int i = 1; i <= h1; i++) 
            for (int j = 1; j <= w1; ++j) {
                int xx = (i - 1)  * dh1 + 1;
                int yy = (j - 1)  * dw1 + 1;
                dm1[xx][yy] = m1[i][j];
                isH[yy] = isV[xx] = 1;
            }

        for (int i = 1; i <= a; ++i)  {
            for (int j = 1; j <= b; ++j) {
                if(isV[i]) {
                    if(!isH[j] and j - 1 >= 1)dm1[i][j] = dm1[i][j - 1];
                    if(!isV[i + 1]) dm1[i + 1][j] = dm1[i][j];
                } else {
                    if(dm1[i][j] == -1 and j - 1 >= 1)dm1[i][j] = dm1[i][j - 1];
                    if(dm1[i + 1][j] == -1)dm1[i + 1][j] = dm1[i][j];
                }
            }
        }

        int dh2 = a / h2;
        int dw2 = b / w2;
        for (int i = 1; i <= h2; i++) 
            for (int j = 1; j <= w2; ++j) {
                int xx = (i - 1)  * dh2 + 1;
                int yy = (j - 1)  * dw2 + 1;
                dm2[xx][yy] = m2[i][j];
                isH2[yy] = isV2[xx] = 1;
            }

        for (int i = 1; i <= a; ++i)  {
            for (int j = 1; j <= b; ++j) {
                if(isV2[i]) {
                    if(!isH2[j] and j - 1 >= 1)dm2[i][j] = dm2[i][j - 1];
                    if(!isV2[i + 1]) dm2[i + 1][j] = dm2[i][j];
                } else {
                    if(dm2[i][j] == -1 and j - 1 >= 1) dm2[i][j] = dm2[i][j - 1];
                    if(dm2[i + 1][j] == -1) dm2[i + 1][j] = dm2[i][j];
                }
            }
        }

        for (int i = 1; i <= a; ++i)  {
            for (int j = 1; j <= b; ++j)
                cout << dm2[i][j];
            cout << "\n";
        }
        int ans = 0;
        for (int i = 1; i<= a; ++i) 
            for (int j = 1; j <= b; ++j)
                ans += dm1[i][j] == dm2[i][j];
        cout << ans << "\n";

    }
    /*
       1     
       4 3
       010101101111
       5 2
       0101110101  
     * */
    return 0;
}

