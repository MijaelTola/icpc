#include <bits/stdc++.h>

using namespace std;

int main() {
    string a,s;
    cin >> a >> s;

    //adding

    set<string> ans;

    for (int i = 0; i < (int)s.size(); ++i) {
        for (auto A: a) {
            string cur = "";
            for (int j = 0; j < (int)s.size(); ++j) {
                if(j == i) cur += A;
                cur += s[j];
            }
            ans.insert(s + A);
            ans.insert(cur);
        }
    }

    //Removing
    for (int i = 0; i < (int)s.size(); ++i) {
        string cur = "";
        for (int j = 0; j < (int)s.size(); ++j) {
            if(j == i) continue;
            cur += s[j];
        }
        ans.insert(cur);
    }

    //changing
    for (int i = 0; i < (int)s.size(); ++i) {
        for (auto A: a) {
            string cur = "";
            for (int j = 0; j < (int)s.size(); ++j) {
                if(j == i) cur += A;
                else cur += s[j];
            }
            if(cur != s) ans.insert(cur);
        }
    }
    for (auto x: ans)
        cout << x << "\n";
    return 0;
}

