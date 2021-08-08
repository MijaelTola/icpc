#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    int caso = 1;
    while(t--) {
        int n,k;
        cin >> n >> k;

        vector<int> v;
        map<int,int> mp;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        v.push_back(0);
        v.push_back(k + 1);
        sort(v.begin(), v.end());

        int mx = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                for (auto di: {-1, 1}) {
                    for (auto dj: {-1, 1}) {

                        int l = min(i, i + di);
                        int r = max(i, i + di);
                        
                        int l2 = min(j, j + dj);
                        int r2 = max(j, j + dj);

                        if(l == l2 and r == r2) {
                            mx = max((v[r] - v[l]) - 1, mx);
                            continue;
                        }

                        int c1 = 0;
                        if(l == 0) c1 = v[r] - 1;
                        else c1 = (v[r] - v[l]) / 2;

                        int c2 = 0;
                        if(v[r2] == k + 1) c2 = k - v[l2];
                        else c2 = (v[r2] - v[l2]) / 2;
                        
                        mx = max(mx, c1 + c2);

                    }
                }
            }
        }
        
        cout << "Case #" << caso++ << ": ";
        cout.precision(10);
        cout << fixed << 1. * mx / k << "\n";

    }
    return 0;
}

