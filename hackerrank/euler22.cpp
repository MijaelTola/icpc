#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    
    auto get = [&] (const string &x) {
        int sum = 0;
        for (auto c: x)
            sum += (c - 'A' + 1);
        return sum;
    };

    map<string, int> ans;

    for (int i = 0; i < n; ++i) { 
        ans[v[i]] = get(v[i]) * (i + 1);
    }

    int q;
    cin >> q;

    while(q--) {
        string x;
        cin >> x;
        cout << ans[x] << "\n";
    }
    

    return 0;
}

