#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    string s;
    cin >> n >> s;

    for (char x: s) {
        int y = x - 'A';
        int v = (y + n) % 26;
        cout << (char)(v + 'A');
    }
    cout << "\n";
    return 0;
}

