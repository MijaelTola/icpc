#include <bits/stdc++.h>

using namespace std;

bool is[100010];
long long ans[100010];

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


    for (int i = 2; i <= 100000; ++i) {
       is[i] = check(check(i)) == i and i != check(i);
       if(is[i]) 
           ans[i] = i;
       ans[i] += ans[i - 1];
    }

    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }
    return 0;
}

