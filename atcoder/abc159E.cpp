#include <bits/stdc++.h>

using namespace std;

int h,w,dk;
int aux[11][1010];
char c[11][1010];

int query(int a,int b, int x, int y) {
    int ans = aux[x][y];
    if(a) ans -= aux[a - 1][y];
    if(b) ans -= aux[x][b - 1];
    if(a and b) ans += aux[a - 1][b - 1];
    return ans;
}

int main() {

    cin >> h >> w >> dk;

    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> c[i][j];

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            aux[i][j] = c[i][j] - '0';
            if(i) aux[i][j] += aux[i - 1][j];
            if(j) aux[i][j] += aux[i][j - 1];
            if(i and j) aux[i][j] -= aux[i - 1][j - 1];
        }
    }

    int ans = 1e9;
    
    if(w == 1) {
        int a = 0;
        int ans = 0;
        for (int i = 0; i < h ;++i) {
            a += c[i][0] - '0';
            if(a > dk) {
                ans++;
                a = c[i][0] - '0';
            }
            
        }
        cout << ans << "\n";
        return 0;
    }
    for (int i = 0; i < (1 << h); ++i) {
        int j = 0;
        int cur = 0;
        while(j < w) {
            int a = j, b = w + 1;
            while(b - a > 1) {
                int mid = (a + b) / 2;
                int last = -1;
                bool flag = 1;
                for (int k = 0; k < h; ++k) {
                    if(i & (1 << k)) {
                        int val = query(last + 1, j, k, mid);
                        flag &= val <= dk;
                        last = k;
                    }
                }
                flag &= query(last + 1, j, h - 1, mid) <= dk;
                if(flag) a = mid;
                else b = mid;
            }
            j = a + 1;
            if(j < w) cur++;
            
        }
        ans = min(ans, cur + __builtin_popcount(i));
    }
    cout << ans << "\n";

    return 0;
}

