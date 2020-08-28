#include <bits/stdc++.h>

using namespace std;

int main() {

    int r,c,a,b;
    cin >> r >> c >> a >> b;

    vector<int> aa,bb;
    for (int i = 0; i < a; ++i) {
        int x;
        cin >> x;
        aa.push_back(x);
    }

    for (int i = 0; i < b; ++i) {
        int x;
        cin >> x;
        bb.push_back(x);
    }

    bool flag = 0;
    int dx = 0;
    for (int x: aa) {
        for (int i = 0; i < x; ++i, dx++) {
            int dy = 0;
            bool cur = !flag;
            for (int y: bb) {
                for (int j = 0; j < y; ++j, dy++) {
                    if(cur) cout << "B";
                    else cout << "W";
                }
                cur = !cur;
            }
            cout << "\n";
        }
        flag = !flag;
    }

    return 0 ;
}

