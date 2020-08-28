#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        bool flag = 1;
        int a = 0, b = 1 << n;
        while(b - a > 1) {
            double mid = (a + b) / 2.0;
            if(flag) {
                b = mid;
                flag = 0;
            } else {
                a = mid;
                flag = 1;
            }
        }
        if(flag) printf("%d %d\n", a, (1 << n));
        else printf("%d %d\n", b, (1 << n));
   }

    return 0;
}

