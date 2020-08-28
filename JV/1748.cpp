#include <bits/stdc++.h>

using namespace std;

int t,n;
int v[100010];

bool ver(int k) {
    int last = 0;
    for (int i = 0; i < n; ++i) {
        if(!k) return 0;
        int cur = abs(last - v[i]);
        if(cur > k) return 0;
        if(cur == k) k--;
        last = v[i];
    }
    return 1;
}
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", v + i);

        int a = -1, b = 1e8;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(ver(mid)) b = mid;
            else a = mid;
        }
        printf("%d\n", b);
    }
    return 0;
}

