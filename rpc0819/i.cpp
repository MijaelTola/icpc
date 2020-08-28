#include <bits/stdc++.h>

using namespace std;

int a[27];

int main() {
    
    string s;
    cin >> s;

    for (char x: s)
        a[x - 'a']++;
    
    bool i = 0, j = 0;
    for (int k = 0; k < 27; ++k) {
        i |= (a[k] and a[k] % 2 == 0);
        j |= (a[k] and a[k] & 1);
    }
    if(i and j) cout << "2\n";
    if(i and !j) cout << "0\n";
    if(!i and j) cout << "1\n";
    return 0;
}

