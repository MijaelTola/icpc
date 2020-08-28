#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long a,b;
    cin >> a >> b;
    set<long long> ans;
    for (long long i = 1; i * i <= a; ++i) {
        if(a % i == 0) {
            if(i % b == 0) ans.insert(i);
            long long dv = a / i;
            if(dv % b == 0) ans.insert(dv);
        }
    }

    for (long long x: ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}

