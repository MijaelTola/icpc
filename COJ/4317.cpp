#include <bits/stdc++.h>

using namespace std;

bool ver(char x) {
    return x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string s;
        getline(cin,s);
        for (int i = 0; i < (int)s.size(); ++i) {
            if(ver(s[i])) cout << s[i] << "p" << s[i];
            else cout << s[i];
        }
        cout << "\n";
    }
    return 0;
}

