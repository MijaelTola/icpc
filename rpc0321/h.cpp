#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<pair<int,char> > v;

    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;

        for (int j = 0; j < c; ++j) {
            int x;
            cin >> x;
            v.push_back({x, (char)(i + 'A')});
        }

       
    }
    sort(v.begin(), v.end());


    for (int j = 0; j < (int)v.size(); ++j) {
        cout << v[j].second;
    }
    cout << "\n";
    return 0;
}

