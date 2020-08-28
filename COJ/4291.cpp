#include <bits/stdc++.h>

using namespace std;

char a[20], b[20];
int main() {
    int da,db;
    while(scanf("%s %d %s %d", a, &da, b, &db) != EOF) {
        char x = a[0];
        char y = b[0];
        if(x == y) {
            if(da == db) puts("Draw");
            else puts(da > db ? "Tobby":"Naebbirac");
            continue;   
        }
        if(x == 'B') {
            if(y == 'D') puts(2 * da <=  db ? "Naebbirac": "Tobby");
            else puts(da >= 2 * db ? "Tobby":"Naebbirac");
            continue;
        }

        if(x == 'C') {
            if(y == 'B') puts(2 * da <= db ? "Naebbirac": "Tobby");
            else puts(da >= 2 * db ? "Tobby":"Naebbirac");
            continue;
        }

        if(x == 'D') {
            if(y == 'C') puts(2 * da <= db ? "Naebbirac": "Tobby");
            else puts(da >= 2 * db ? "Tobby":"Naebbirac");
            continue;
        }
    }
    return 0;
}

