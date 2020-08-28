#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int cur = 1;
        if(n & 1) {
        

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    cout << cur++ << " ";
                }
                cout << "\n";
            }

        } else {

            for (int i = 0; i < n; ++i) {
                if(i & 1) {
                    cur += n;
                    cur--;
                    for (int j = 0; j < n; ++j)
                        cout << cur-- << " ";
                    cur += n + 1;
                } else {
                    for (int j = 0; j < n; ++j)
                        cout << cur++ << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}

