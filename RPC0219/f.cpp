#include <bits/stdc++.h>

using namespace std;

int d[11];
int main() {
    string s;
    cin >> s;

    for (char x: s)
        d[x - '0']++;
    
    int mn = 1e9;
    int id = -1;
    for (int i = 1; i < 10; ++i) {
        if(!d[i]) return cout << i << "\n",0;
        if(d[i] < mn) {
            mn = d[i];
            id = i;
        }
    }

    int s1 = 1 + (d[0] + 1);
    int s2 = d[id] + 1;

    if(s1 <= s2) {
        cout << 1;
        for (int i = 0; i < d[0] + 1; i++)
            cout << 0;
    } else {
        for (int j = 0; j < d[id] + 1; ++j)
            cout << id;
    }
    cout << "\n";
    return 0;
}

