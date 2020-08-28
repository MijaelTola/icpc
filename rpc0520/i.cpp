#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,m;
    cin >> n >> m;

    set<string> s;

    while(n--) {
        string x;
        cin >> x;
        s.insert(x);
    }


    map<char,char> mp;
    mp['0'] = 'O';
    mp['1'] = 'L';
    mp['2'] = 'Z';
    mp['3'] = 'E';
    mp['5'] = 'S';
    mp['6'] = 'B';
    mp['7'] = 'T';
    mp['8'] = 'B';


    while(m--) {
        string x;
        cin >> x;
        
        bool flag = 0;
        for (int i = 0; i < (int)x.size(); ++i) {
            string cur = "";
            for (int j = i; j < (int)x.size(); ++j) {
                if('0' <= x[j] and x[j] <= '9') {
                    cur += mp[x[j]];
                } else cur += x[j];
                flag |= s.count(cur);
            }
        }
        if(flag) cout << "INVALID\n";
        else cout << "VALID\n";
    }
    return 0;
}

