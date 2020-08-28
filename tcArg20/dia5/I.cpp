#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        string s;
        cin >> n >> s;

        int l = 0, r = n - 1;

        bool flag = 1;
        while(l < r) {

            flag &= abs(s[l] - s[r]) == 2 or s[l] == s[r];
            l++,r--;
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

