#include <bits/stdc++.h>

using namespace std;

int c[22][22];
int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k) {
        int x,y;
        cin >> x >> y;
        int a,b;
        a = x, b = y;
        if(a > b) swap(a,b);
        cout << "CASE #" <<  k << ": ";;
        if(x == 2 and y == 2) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        cout << "POSSIBLE\n";
        int cur = 1;    
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; j += 2) {
                if(x > y) cout << i + 1 << " " << j + 1 << "\n";
                else cout << j + 1 << " " << i + 1 << "\n";
                c[i][j] = cur++;
            }
        }

        for (int i = 0; i < a; ++i) {
            for (int j = 1; j < b; j += 2) {
                if(x > y) cout << i + 1 << " " << j + 1 << "\n";
                else cout  << j + 1 << " " << i + 1 << "\n";
                c[i][j] = cur++;
            }
        }
    }
    return 0;
}


