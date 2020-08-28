#include <bits/stdc++.h>

using namespace std;

int t;
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    for (int cs = 1; cs <= t; ++cs) {
        cin >> s;
        
        cout << "Case #" << cs << ": ";
        string cur = "";
        for (int i = 0; i < (int)s.size(); ++i) {
            if(s[i] == '0') {
                int c = 0;
                for (char x: cur) {
                    while(c > x - '0' and c) {
                        cout << ')';
                        c--;
                    }
                    while(c < x - '0') {
                        cout << '(';
                        c++;
                    }
                    cout << x;
                }
                while(c--) cout << ')';
                cout << s[i];
                cur = "";
            } else cur += s[i];
        }
        int c = 0;
        for (char x: cur) {
            while(c > x - '0' and c) {
                cout << ')';
                c--;
            }
            while(c < x - '0') {
                cout << '(';
                c++;
            }
            cout << x;
        }
        while(c--) cout << ')';
        cout << "\n";
    }




    return 0;
}

