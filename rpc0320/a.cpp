#include <bits/stdc++.h>

using namespace std;

const int M = 1010;

double si[20];
double no[20];

int X[M], Y[M];
double p[M];

int main() {
    int n, m;
    while(cin >> n >> m) {
        for (int i = 0; i < m; i++) {
            int x, y;
            double c;
            cin >> x >> y >> c;
            x--; y--;
            X[i] = x;
            Y[i] = y;
            p[i] = c;
        }

        for (int i = 0; i < n; ++i) {
            si[i] = 1;
            no[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            double c;
            a = X[i]; b = Y[i]; c = p[i];
            double _s = si[b], _n = no[b];
            si[b] = si[a]*_s*(1-c)        +no[a]*_s;
            no[b] = si[a]*_s*c    +_n;
        }
        cout << fixed << setprecision(7);
        for(int i = 0; i < n; i++) {
            cout << si[i] << "\n";
        }
    }
    return 0;
}

