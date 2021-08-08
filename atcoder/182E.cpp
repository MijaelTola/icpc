#include <bits/stdc++.h>

using namespace std;

int c[1510][1510];
int c2[1510][1510];


int main() {
    memset(c, 0, sizeof c);
    int h,w,n,m;
    cin >> h >> w >> n >> m;
 
    vector<pair<int,int> > luz;
    vector<pair<int,int> > bloques;


    for (int i = 0; i < n; ++i) {
        int a,b;
        cin >> a >> b;
        luz.push_back({a,b});
    }

    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        c[a][b] = c2[a][b] = 2;
    }


    for (auto [x,y]: luz) {
        
        int pos = y;
        while(pos >= 0 and c[x][pos] == 0) c[x][pos] = 1, pos--;

        pos = y + 1;
        while(pos <= w and c[x][pos] == 0) c[x][pos] = 1, pos++;

        pos = x;
        while(pos >= 0 and c2[pos][y] == 0) c2[pos][y] = 1, pos--;


        pos = x + 1;
        while(pos <= h and c2[pos][y] == 0) c2[pos][y] = 1, pos++;

    }

    int ans = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            ans += c[i][j] == 1 or c2[i][j] == 1;
            //cout << (c[i][j] == 1 or c2[i][j] == 1) << " ";
        }
        //cout << "\n";
    }

    cout << ans << "\n";

    return 0;
}

