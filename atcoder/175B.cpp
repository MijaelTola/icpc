#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    vector<int> v(n);

    for (int &x: v)
        cin >> x;
    
    int ans = 0;
    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if(v[i] < v[j] and v[j] < v[k]) {
                    if(v[i] + v[j] > v[k] and v[i] + v[k] > v[j] and v[k] + v[j] > v[i])
                        ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}

