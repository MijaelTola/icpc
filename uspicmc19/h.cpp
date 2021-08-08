#include <bits/stdc++.h>

using namespace std;

int n;

set<pair<int,int> > s;
int f(int pos, int a, int b) {
    if(pos == n) {
        s.insert({a,b});
        return 1;
    }

    int ans = 0;
    for (int i = 0; i < 3; ++i)
        if(i * a <= b * b)  {
            ans += f(pos + 1, b, i);
        }
    return ans;
}

const int mod = 1e9 + 7;
int main() {

    cin >> n;

    int ans = 0;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                if(i * k <= j * j) {
                    ans += f(3,j , k);
                }

    cout << ans << "\n";

    for (auto [x, y]: s)
        cout << x << " " << y << "\n";
    return 0;
}
