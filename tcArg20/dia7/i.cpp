#include <bits/stdc++.h>

using namespace std;

int n;


int main() {

    cin >> n;
    int da = -1, db = -1;
    vector<int> a,b;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x) a.push_back(x);
        if(x == 1) da = a.size() - 1;
    }

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x) b.push_back(x);
        if(x == 1) db = b.size() - 1;;
    }

 
    bool flag = 1;


    for (int i = 0; i < (int)a.size(); ++i, da = (da + 1) % a.size(), db = (db + 1) % a.size()) {
        flag &= a[da] == b[db];
    }

    if(flag)cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

