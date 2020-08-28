#include <bits/stdc++.h>

using namespace std;

char c[30][30];

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> c[i][j];

    bool flag = 1;

    for (int i = 0; i < n; ++i) {
        int a = 0, b = 0;
        int cnt = 0;
        char last = '.';
        
        for (int j = 0; j < n; ++j) {
            if(c[i][j] == 'W') a++;
            else b++;
            if(last == c[i][j])cnt++;
            else cnt = 1;
            flag &= cnt < 3;
            last = c[i][j];
        }

        flag &= cnt < 3;
        flag &= a == b;
        a = 0, b = 0, cnt = 0;
        last = '.';
         
        for (int j = 0; j < n; ++j) {
            if(c[j][i] == 'W') a++;
            else b++;
            if(last == c[j][i]) cnt++;
            else cnt = 1;
            flag &= cnt < 3;
            last = c[j][i];
        }
        flag &= a == b;
        flag &= cnt < 3;

    }

    cout << flag << "\n";
    return 0;
}

