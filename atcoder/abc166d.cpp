#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<pair<long long, int> > v;
    for (long long i = 0; i * i * i * i * i <= 4e18; ++i) {
        v.push_back({i * i * i * i * i, i});
        v.push_back({-i * -i * -i * -i * -i, -i});
    }
    for (int i = 0; i < (int)v.size(); ++i) {
        for (int j = 0; j < (int)v.size(); ++j) {
            if(v[i].first + v[j].first == n) {
                return cout << v[i].second << " " << -v[j].second << "\n",0;
            }
        }
    }
    return 0;
}

