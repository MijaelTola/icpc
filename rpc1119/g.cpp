#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    cin >> s;

    int c = 0;
    for (int i = 0; i < s.size(); ++i)
        c += s[i] == 'e';
    cout << "h";
    c <<= 1;
    while(c--)  cout << "e";
    cout << "y\n";
    return 0;
}

