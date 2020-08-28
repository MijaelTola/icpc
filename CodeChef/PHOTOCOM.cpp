#include <bits/stdc++.h>

using namespace std;

int m1[1010][1010]; 
int m2[1010][1010];
int dm1[12010][12010];
int dm2[12010][12010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int h1,w1;
        cin >> h1 >> w1;
        string s; cin >> s;

        for (int i = 1; i <= h1; ++i)
            for (int j = 1; j <= w1; ++j) {
                int x = s[((i - 1) * w1 + j) - 1] - '0';
                m1[i][j] = x;
            }
        
        int h2,w2;
        cin >> h2 >> w2;
        cin >> s;

        for (int i = 1; i <= h2; ++i)
            for (int j = 1; j <= w2; ++j) {
                int x = s[((i - 1) * w2 + j) - 1] - '0';
                m2[i][j] = x;
            }
        
        int a = (h1 * h2) / __gcd(h1,h2);
        int b = (w1 * w2) / __gcd(w1,w2);
        
        int dh1 = a / h1;
        int dw1 = b / w1;
        for (int i = 1; i <= h1; ++i) 
            for (int j = 1; j <= w1; ++j) 
                for (int l = 1; l <= dh1; ++l) 
                    for (int k = 1; k <= dw1; ++k) 
                        dm1[(i - 1) * dh1 + l][(j - 1) * dw1 + k] = m1[i][j];
    
        int dh2 = a / h2;
        int dw2 = b / w2;
        
        for (int i = 1; i <= h2; ++i) 
            for (int j = 1; j <= w2; ++j) 
                for (int l = 1; l <= dh2; ++l) 
                    for (int k = 1; k <= dw2; ++k) 
                        dm2[(i - 1) * dh2 + l][(j - 1) * dw2 + k] = m2[i][j];

        for (int i = 1; i <= a; ++i) {
            for (int j = 1; j <= b; ++j)
                cout << dm2[i][j];
            cout << "\n";
        }
        int ans = 0;
        for (int i = 1; i <= a; ++i) 
            for (int j = 1; j <= b; ++j)
                ans += dm2[i][j] == dm1[i][j];
        cout << ans << "\n";

    }
    return 0;
}

