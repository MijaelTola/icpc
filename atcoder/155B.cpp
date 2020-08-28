#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    bool flag = 1;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x % 2 == 0) {
            flag &= x % 3 == 0 or x % 5 == 0;
        }
    }

    puts(flag ? "APPROVED" : "DENIED");
    return 0;
}

