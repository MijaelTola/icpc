#include <bits/stdc++.h>

using namespace std;

int main() {

    long long x;
    cin >> x;

    auto ver = [&] (long long a) {
        if(a == 0) return false;
        bool flag = 1;
        while(a > 0) {
            flag &= (a % 10LL) == 7 or (a % 10LL) == 4;
            a /= 10LL;
        }
        return flag;
    };

    long long cnt = 0;

    while(x > 0) {
        cnt += ver(x % 10LL);
        x /= 10LL;
    }

    if(ver(cnt) and cnt) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

