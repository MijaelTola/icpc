#include <bits/stdc++.h>

using namespace std;

int t,n,x,q,l,r,dl,dr,total, cur;
int near[61][100010][2];

int main() {
    scanf("%d", &t);
    while(t--) {
        vector<int> v[61];
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            v[x].push_back(i);
        }
        memset(near, -1, sizeof near);
        for (int i = 1; i <= 60; ++i) {
            for (int j = 0; j < (int)v[i].size(); ++j) {
                int x = v[i][j];
                near[i][x][0] = near[i][x][1] = j;
            }

            for (int j = 1; j < n; ++j) 
                if(near[i][j][0] == -1) near[i][j][0] = near[i][j - 1][0];

            for (int j = n - 1; j >= 0; j--)
                if(near[i][j][1] == -1) near[i][j][1] = near[i][j + 1][1];
        }

        scanf("%d", &q);
        while(q--) {
            scanf("%d %d", &l, &r);
            l--,r--;
            total = 0;
            for (int i = 1; i <= 60; ++i) {
                if(!v[i].size()) continue;
                dl = near[i][l][1];
                dr = near[i][r][0];
                if(dl == -1) dl = dr;
                if(dr == -1) dr = dl;
                cur = (dr - dl + 1) >> 1;
                total += cur << 1;
            }
            printf("%d\n", (r - l + 1) - total);
        }
    }
    return 0;
}

