#include <bits/stdc++.h>

using namespace std;

int vis[10010];

int main() {
    
    int ini = 2018;
    int month = 3;

    while(ini < 10010) {
        vis[ini] = 1;
        for (int j = 0; j < 26; ++j) {
            month++;
            if(month > 11) ini++, month = 0;
        }
    }

    int x;
    cin >> x;
    if(vis[x])cout << "yes\n";
    else cout << "no\n";


    return 0;
}

