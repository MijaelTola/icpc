#include <bits/stdc++.h>

using namespace std;

bool m[3][3];
map<int, pair<int,int> > mp;
int main() {

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int x;
            cin >> x;
            mp[x] = {i,j};
        }
    }

    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        if(!mp.count(x)) continue;
        m[mp[x].first][mp[x].second] = 1;
    }

    bool flag = 0;
    for (int i = 0; i < 3; ++i) {
        bool f = 1;
        bool f2 = 1;
        for (int j = 0;j < 3; ++j) {
            f &= m[i][j];
            f2 &= m[j][i];
        }
        flag |= f;
        flag |= f2;
    }

    flag |= (m[0][0] and m[1][1] and m[2][2]);
    flag |= (m[0][2] and m[1][1] and m[2][0]);
    puts(flag ? "Yes" : "No");
    return 0;
}

