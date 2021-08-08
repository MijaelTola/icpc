#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,k;
    cin >> n >> k;

    vector<int> v(n);

    for (auto &x: v)
        cin >> x;

    unordered_map<int,int> mp;
    set<int> s;

    for (int i = 0; i < k; ++i) {
        int x = v[i];
        mp[x]++;
        if(mp[x] == 1) s.insert(x);
        else s.erase(x);
    }


    if(s.size() > 0) cout << *s.rbegin() << "\n";
    else cout << "Nothing\n";

    for (int i = k, ini = 0; i < n; ++i, ini++) {
        int val = v[ini];
        mp[val]--;
        if(mp[val] != 1) s.erase(val);
        else s.insert(val);
        int val2 = v[i];
        mp[val2]++;
        if(mp[val2] != 1) s.erase(val2);
        else s.insert(val2);
        if(s.size() > 0) cout << *s.rbegin() << "\n";
        else cout << "Nothing\n";
    }

    return 0;
}

