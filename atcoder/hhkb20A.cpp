#include <bits/stdc++.h>

using namespace std;

int main() {

    char a,b;
    cin >> a >> b;

    if(a == 'Y') cout << (char)toupper(b) << "\n";
    else cout << (char)tolower(b) << "\n";
    return 0;
}

