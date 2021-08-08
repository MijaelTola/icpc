#include <bits/stdc++.h>

using namespace std;

int n;
char c[110][110];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


int main() {
    
    for (int i = 0; i < 110; ++i)
        for (int j = 0; j < 110; ++j)
            c[i][j] = '.';

    cin >> n;

    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j)
            cin >> c[i][j];

    int total = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(c[i][j] == '.') {
                int a = 0, b = 0;
                for (int k = 0; k < 4; ++k) {
                    int u = dx[k] + i;
                    int v = dy[k] + j;
                    if(u >= 0 and v >= 0 and v <= n + 1 and u <= n + 1) {
                        if(c[u][v] == '*') a++;
                        else b++;
                    }
                }
                total += a == b;
            }
        }
    }


    cout << total << "\n";

    return 0;
}

