#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> a,b;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(x & 1) a.push_back(i);
            else b.push_back(i);
        }

        if(b.size()) {
            cout << b.size() << "\n";
            for (int i = 0; i < (int)b.size(); ++i)
                cout << b[i] + 1<< " ";
            cout << "\n";
        } else if(a.size() >= 2) {
            while(a.size() & 1) a.pop_back();
            cout << a.size() << "\n";
            for (int i = 0; i < (int)a.size(); ++i)
                cout << a[i] + 1 << " ";
            cout << "\n";
        } else cout << "-1\n";
    }
    return 0;
}

