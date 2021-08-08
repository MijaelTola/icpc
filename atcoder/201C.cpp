#include <bits/stdc++.h>

using namespace std;

string s;
int has[11];
int no[11];

int main() {

    cin >> s;

    for (int i = 0; i < 10; ++i) {
        if(s[i] == 'o') has[i] = 1;
        if(s[i] == 'x') no[i] = 1;
    }

    auto check = [&] (string num, int x) {
        for (auto c: num)
            if((c - '0') == x) return 1;
        return 0;
    };

    int ans = 0;
    for (int i = 0; i < 10000; ++i) {
        bool flag = 1;
        string cur = to_string(i);
        while((int)cur.size() < 4)
            cur = "0" + cur;
        for (int j = 0; j < 10; ++j) {
            if(has[j]) {
                flag &= check(cur, j);
            }
            if(no[j]) 
                flag &= !check(cur,j);
        }

        ans += flag;
    }

    cout << ans << "\n";
    return 0;
}

