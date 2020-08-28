#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    vector<pair<int,int> > v;
    
    map<int, set<int> > mpx, mpy;

    for (int i = 0 ; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.emplace_back(x,y);
        mpx[x].insert(y);
        mpy[y].insert(x);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
        
        }
    }
    return 0;
}

