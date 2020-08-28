#include <bits/stdc++.h>

using namespace std;

int c[1010][1010];
int dx[1010];
int dy[1010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> c[i][j];
    
    for (int i = 0; i < max(n,m); ++i)
        dy[i] = dx[i] = i;
    while(k--) {
        char t;
        int x,y;
        cin >> t >> x >> y;
        x--,y--;
        if(t == 'c') swap(dx[x], dx[y]);
        if(t == 'r') swap(dy[x], dy[y]);
        if(t == 'g') cout << c[dy[x]][dx[y]] << "\n";
    }
    return 0;
}

