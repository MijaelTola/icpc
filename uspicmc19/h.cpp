#include <bits/stdc++.h>

using namespace std;

int n;

long long f(int pos, int a, int b) {
    if(pos == n) return 1;

    long long ans = 0;
    for (int i = 0; i < 3; ++i)
        if(i * a <= b * b)  {
            ans += f(pos + 1, b, i);
        }
    return ans;
}

int main() {
    
    int last = 0;
    for (n = 3; n <= 20; ++n) {
        int ans = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    if(i * k <= j * j) {
                        ans += f(3,j , k);
                    }

        cout << ans - last << "\n";
        last = ans;
    }
    return 0;
}

