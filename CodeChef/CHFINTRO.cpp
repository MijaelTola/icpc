#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,r;
    cin >> n >> r;
    
    while(n--) {
        int x; cin >> x;
        if(x >= r) puts("Good boi");
        else puts("Bad boi");
    }
    return 0;
}

