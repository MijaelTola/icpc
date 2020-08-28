#include <bits/stdc++.h>

using namespace std;

int t;
int v[100010];
int main() {
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long double sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            sum += v[i];
        }
        int id = -1;
        for (int i = 0; i < n; ++i) {
            if(sum / (double)n == (sum - v[i]) / (double)(n - 1)) {
                id = i;
                break;
            }
        }
        if(id == -1) cout << "Impossible\n";
        else cout << id + 1<< "\n";

    }
    return 0;
}

