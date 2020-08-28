#include <bits/stdc++.h>

using namespace std;

int a[30],b[30];
int main() {

    string s,t;
    cin >> s >> t;

    int ans = 0;
    for (int i = 0; i < (int)s.size(); ++i)
        ans += s[i] != t[i];
    cout << ans << "\n";


    return 0;
}

