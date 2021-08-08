#include <bits/stdc++.h>

using namespace std;


int main() {

    int n;
    scanf("%d", &n);
    
    multiset<int> s;

    int mid = (n + 1) / 2 + 1;
    if(n % 2 == 0) mid = n / 2 + 1;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        s.insert(x);
        while((int)s.size() > mid) s.erase(s.lower_bound(*s.rbegin()));
    }
    if(n & 1) {
        if(n != 1) s.erase(s.lower_bound(*s.rbegin()));
        printf("%.1lf\n", 1. **s.rbegin());
    } else {
        double a = *s.rbegin();
        s.erase(s.lower_bound(*s.rbegin()));
        double b = *s.rbegin();

        printf("%.1lf\n", (a + b) / 2);
    }

    return 0;
}

