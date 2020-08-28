#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    vector<pair<int,int> > v(n);

    for (auto &p: v)
        cin >> p.first >> p.second;

    sort(v.begin(), v.end());

    int a = -1, b = -1, flag = 1;

    for (auto p: v) {
        if(p.first > a) {
            a = p.second;
        } else if(p.first > b) {
            b = p.second;
        } else {
            flag = 0;
            break;
        }
    }

    cout << (flag ? "YES\n" : "NO\n");
    return 0;
}

