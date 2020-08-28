#include <bits/stdc++.h>

using namespace std;

int v[65][100010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; 
    cin >> t;
    while(t--) {
        int n; cin >> n; 
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            v[x][i] = 1;
        }
        for (int i = 1; i <= 60; ++i) 
            for (int j = 1; j < n; ++j) 
                v[i][j] += v[i][j - 1];
        
        int q; cin >> q;


        while(q--) {
            int x,y;
            cin >> x >> y;
            x--,y--;
            int ans = 0;
            for (int i = 1; i <= 60; ++i) {
                int a = v[i][x - 1];
                int b = v[i][y];
                ans += (b - a) % 2;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}

