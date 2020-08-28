#include <bits/stdc++.h>

using namespace std;

int m[110][110];
int main(){

    int t; cin >> t;    
    while(t--) {
        int r,c,h,v;
        cin >> r >> c >> h >> v;

        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j) {
                char x; cin >> x;
                if(x == '@') m[i][j] = 1;
            }

        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j) {
                if(i > 0 and j > 0)
                    m[i][j] += m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1];
            }
        
    }
    return 0;
}

