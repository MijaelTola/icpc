#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    cin >> s;

    if(s == "RRR") return cout << "3" << endl, 0;
    if(s == "SRR") return cout << "2" << endl, 0;
    if(s == "RRS") return cout << "2" << endl, 0;
    
    bool flag = 0;
    for (int i = 0; i < 3; ++i)
        flag |= s[i] == 'R';

    cout << flag << endl;
    return 0;
}

