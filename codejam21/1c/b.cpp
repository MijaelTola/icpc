#include <bits/stdc++.h>

using namespace std;

int main() {


    auto check = [&] (string x) {
        string ini = "";

        string dx = "";
        for (int i = 0; i < (int)x.size(); ++i) {
            dx += x[i];
            int cnt = 0;   
            ini = dx;
            string cur = ini;
            while(cur.size() < x.size()) {
                cnt++;
                ini = to_string(stoi(ini) + 1);
                cur += ini;
            }


            if(x == cur and cnt) {
                return 1;
            }
        }
        return 0;
    };

    int t;
    cin >> t;
    int caso = 1;
    while(t--) {
    
        int y;
        cin >> y;

        y++;
        while(!check(to_string(y))) y++;

        printf("Case #%d: %d\n", caso++, y);

    }
    return 0;
}

