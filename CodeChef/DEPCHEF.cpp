#include <bits/stdc++.h>

using namespace std;

int a[110], d[110];
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) 
            scanf("%d", a + i);
        for (int i = 0; i < n; ++i) 
            scanf("%d", d + i);

        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int l = a[((i - 1) + n) % n];
            int r = a[(i + 1) % n];
            if(d[i] > l + r) 
                ans = max(ans, d[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}

