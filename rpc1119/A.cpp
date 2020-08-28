#include <bits/stdc++.h>

using namespace std;

int a[1010];
int b[1010];
int c[1010][1010];
int vis[1010];

int main() {
    int n,m;
    cin >> n >> m;

    

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < m; ++j)
            c[i][j] = a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        for (int j = 0; j < n; ++j) {
            if(c[j][i] > b[i]) c[j][i] = b[i];
        }
    }
    

    bool flag = 1;

    for (int i = 0; i < n; ++i) {
        int mx = 0;
        for (int j = 0; j < m; ++j) 
            mx = max(mx, c[i][j]);
        flag &= mx == a[i];       
    }
    
    for (int i = 0; i < m; ++i) {
        int mx = 0;
        for (int j = 0; j < n; ++j) 
            mx = max(mx, c[j][i]);
        flag &= mx == b[i];

    }
    puts(flag ? "possible" : "impossible");
    return 0;
}

