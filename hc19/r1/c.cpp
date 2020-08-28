#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        vector<pair<int, pair<int,int> > > v;
        int n,h;
        cin >> n >> h;
        for (int i = 0; i < n; ++i) {
            int x,a,b;
            cin >> x >> a >> b;
            v.push_back({x, {a,b}});
        }
    }
    return 0;
}

