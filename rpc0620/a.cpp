#include <bits/stdc++.h>

using namespace std;

vector<string> v[30],b;
int main() {
    string s;
    int n;
    cin >> s >> n;

    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        b.push_back(x);
        v[x[0] - 'a'].push_back(x);
    }

    int last = s.back() - 'a';
    if(v[last].size() == 0) return cout << "?\n", 0;
    

    for (auto x: v[last]) {
        int llast = x.back() - 'a';
        if(llast == last and v[llast].size() <= 1) return cout << x << "!\n", 0;
        if(v[llast].empty())
            return cout << x << "!\n", 0;
    }

    cout << v[last][0] << "\n";
    return 0;
}

