#include <bits/stdc++.h>

using namespace std;

int v[1010];
int main() {
    
    int t;
    cin >> t;
    Next:
    while(t--) {
        int n,p;
        cin >> n >> p;

        for (int i = 0; i < n; ++i)
            cin >> v[i];
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(p % v[i] != 0) {
                    cout << "YES ";
                    for (int k = 0; k < n; ++k) {
                        if(k != i) cout << "0 ";
                        else cout << p / v[i] + 1 << " ";
                    }
                    cout << "\n";
                    goto Next;
                }
                
                if(i == j) continue;
                int a = p / v[i] - 1;
                int left = p - a * v[i];
                if(left % v[j] != 0) {
                    if(a * v[i] + (left / v[j] + 1) * v[j] - v[i] >= p) continue;
                    if(a * v[i] + (left / v[j] + 1) * v[j] - v[j] >= p) continue;
                    cout << "YES ";
                    for (int k = 0; k < n; ++k) {
                        if(k == i) cout << a << " ";
                        else if(k == j) cout << left / v[j] + 1 << " ";
                        else cout << "0 ";
                    }
                    cout << "\n";
                    goto Next;
                }
                a = p / v[j] - 1;
                left = p - a * v[j];
                if(left % v[i] != 0) {
                    if(a * v[j] + (left / v[i] + 1) * v[i] - v[i] >= p) continue;
                    if(a * v[j] + (left / v[i] + 1) * v[i] - v[j] >= p) continue;
                    cout << "YES ";
                    for (int k = 0; k < n; ++k) {
                        if(k == j) cout << a << " ";
                        else if(k == i) cout << left / v[i] + 1 << " ";
                        else cout << "0 ";
                    }
                    cout << "\n";
                    goto Next;
                }
            }
        }
            cout << "NO\n";
    }
    return 0;
}

