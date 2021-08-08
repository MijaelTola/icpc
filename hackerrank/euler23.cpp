#include <bits/stdc++.h>

using namespace std;

int ans[100010];
int main() {

    auto check = [&](int x) {
        int sum = 0;
        for (int i = 1; i * i <= x; ++i) {
            if(x % i == 0) {
                sum += i;
                if(x / i != i and x / i != x) {
                    sum += x / i;
                }
            }
        }
        return sum;
    };

    vector<int> v;
    for (int i = 1; i <= 100000; ++i) {
        if(check(i) > i) v.push_back(i);
    }
    


    for (auto x: v)
        for (auto y: v)
            if(x + y <= 100000) ans[x + y] = 1;

    int q;
    cin >> q;

    while(q--) {
        int x;
        cin >> x;
        if(ans[x]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

