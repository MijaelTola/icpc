#include <bits/stdc++.h>

using namespace std;

int v[20];
int n;
string s;
int main() {
    cin >> n >> s;

    for (int i = 0; i < n; ++i) {
        if(s[i] == 'L') {
            int pos = 0;
            while(v[pos] and pos < n) pos++;
            v[pos] = 1;
        } else if(s[i] == 'R') {
            int pos = 9;
            while(v[pos] and pos >= 0) pos--;
            v[pos] = 1;
        } else {
            v[s[i] - '0'] = 0;
        }
    }

    for (int i = 0; i < 10; ++i)
        cout << v[i];
    cout << "\n";
    return 0;
}

