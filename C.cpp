#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    int k = 1;
    ini:
    while(t--) {
        int n;
        cin >> n;
        vector<pair<pair<int,int>, int> > v(n);
        vector<char> ans(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].first.first >> v[i].first.second;
            v[i].second = i;
        }

        sort(v.begin(), v.end());
        
        int c = 0, j = 0;

        for (int i = 0; i < n; ++i) {
            if(c <= v[i].first.first) {
                c = v[i].first.second;
                ans[v[i].second] = 'C';
            } else if(j <= v[i].first.first) {
                j = v[i].first.second;
                ans[v[i].second] = 'J';
            } else {
                cout << "Case #" << k++ << ": IMPOSSIBLE\n";
                goto ini;
            }
        }
        

        cout << "Case #" << k++ << ": ";
        for (char x: ans)
            cout << x;
        cout << "\n";
    }
    return 0;
}

