#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,r,k;
        cin >> n >> r >> k;
        vector<int> v;
        
        for (int i = 1; i <= n; ++i) 
            v.push_back(i);
        
        do {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j)
                    if (v[j] < v[i]) cnt++;
            }

            if(cnt != r) continue;
            for (int i = 0; i < n; ++i)
                cout << v[i] << " ";
            cout << "\n";
        }while(next_permutation(v.begin(), v.end()));
    }
    return 0;
}

