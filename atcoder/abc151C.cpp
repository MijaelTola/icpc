#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<string> v[100010];

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x;
        string s;
        cin >> x >> s;
        if(s == "AC") {
            if((int)v[x].size() and v[x].back() == "AC") {}
            else v[x].push_back(s);
        } else {
            if((int)v[x].size() and v[x].back() == "AC") {}
            else v[x].push_back(s);
        }
    }

    int a = 0, b = 0;
    for (int i = 1; i <= n; ++i) {
        if((int)v[i].size() != 0 and v[i].back() == "AC") {
            a++;
            b += v[i].size() - 1;
        }
    }
    cout << a << " " << b << "\n";
    return 0;
}

