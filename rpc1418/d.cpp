#include <bits/stdc++.h>

using namespace std;

int main() {
    int r,p;
    while(cin >> r >> p) {

        if(r > p) puts("Interpersonal");
        if(p > r) puts("Technical");
        if(r == p) puts("Either");
    }
    return 0;
}

