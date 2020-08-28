#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        map<int,int> in,out;
        int n;
        cin >> n;
        vector<int> a,b;
        for (int i = 0; i < 4 * n - 1; ++i) {
            int x,y;
            cin >> x >> y;
            a.push_back(x);
            b.push_back(y);
            in[x]++;
            out[y]++;
        }

        int ax = -1, ay = -1;

        for (int x: a) {
            if(in[x] & 1) ax = x;
        }

        for (int x: b) 
            if(out[x] & 1) ay = x;
        
        cout << ax << " " << ay << "\n";
    }

    return 0;
}

