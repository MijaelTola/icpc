#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int m[3][3];
int main() {
#ifdef JUDGE
    freopen("input.txt","rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> m[i][j];
    
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if(i != j && j != k && i != k) {
                    int a = m[0][i] * m[0][i] + m[1][j] * m[1][j] + m[2][k] * m[2][k];
                    ans = max(ans, a);
                }
            }
        }
    }
    cout.precision(10);
    cout << sqrt(ans) << "\n";
    return 0;
}

