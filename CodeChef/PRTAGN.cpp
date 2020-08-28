#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        int q;
        cin >> q;
        set<int> s;
        while(q--) {
            int x;
            cin >> x;
            vector<int> v;
            for (int y: s) 
                if(x != y) v.push_back(x ^ y);
            v.push_back(x);
            for (int y: v)
                s.insert(y);

            int a = 0, b = 0;
            for (int y: s) {
                if(__builtin_popcount(y) & 1) b++;
                else a++;
            }
            cout << a << " " << b << "\n";
        }
    }
    return 0;
}
