#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    while(getline(cin, s) and s != "END") {
        char x = s[0];
        assert(x == 'P' or x == 'G' or x == 'R');
    }
    return 0;
}

