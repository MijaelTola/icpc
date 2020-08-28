#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    cin >> s;

    auto check = [&](string x) {
        
        int cnt = 0;
        for (int i = 0; i <= (int)s.size() - (int)x.size(); ++i) {
            string t = s.substr(i, x.size());
            cnt += x == t;
        }

        return cnt;
    };


    int flag = 0;

    flag += check("Danil");
    flag += check("Olya");
    flag += check("Slava");
    flag += check("Ann");
    flag += check("Nikita");

    if(flag == 1) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

