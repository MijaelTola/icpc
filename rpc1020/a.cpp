#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    set<string> s;

    while(n--) {
        string x;
        cin >> x;
        s.insert(x);
    }

    cout << s.size() << "\n";
    return 0;
}

