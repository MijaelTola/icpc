#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v(n);
    set<pair<int,int> > s;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert({x, i});
        v[i] = x;
    }

    vector<pair<int,int> > ans;
    auto check = [&] () {
        for (int i = 0; i < n; ++i)
            if(v[i]) return 1;
        return 0;
    };
    while(check()) {
        int id = -1;
        for (int i = 0; i < n; ++i) {
            if(v[i] == 1) {
                id = i;
                break;
            }
        }

        if(id == -1) return cout << "-1\n", 0;

        int r = id + 1;
        for (int i = 0; v[r] == 0 and i < n; ++i, r = (r + 1) % n) {
        }

        int l = (id - 1 + n) % n;

        for (int i = 0; v[l] == 0 and i < n; ++i, l = (l - 1 + n) % n) {
        }

        if(r == l or r == id or l == id) return cout << "-1\n", 0;

        v[l]--, v[r]--, v[id]--;
        ans.push_back({min(l,r), max(l,r)});
    }

    sort(ans.begin(), ans.end());
    ans.pop_back();
    for (auto p: ans)
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    return 0;
}

