#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    map<string, int> mp;

    while(n--) {
        string s;
        cin >> s;
        mp[s]++;
    }

    cout << "AC x " << mp["AC"] << "\n";
    cout << "WA x " << mp["WA"] << "\n";
    cout << "TLE x " << mp["TLE"] << "\n";
    cout << "RE x " << mp["RE"] << "\n";
    return 0;
}

