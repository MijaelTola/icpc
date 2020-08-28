#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string pan = "pancakes";
    string pea = "pea soup";
    string ans = "";
    int n;
    cin >> n;
    

    while(n--) {
        int x;
        cin >> x;
        string s,t;
        cin.ignore();
        getline(cin,s);
        bool a = 0, b = 0;
        while(x--) {
            getline(cin,t);
            a |= t == pan;
            b |= t == pea;
        }

        if(a and b and ans == "")
            ans = s;
    }

    if(ans != "")cout << ans << "\n";
    else cout << "Anywhere is fine I guess\n";
    return 0;
}

