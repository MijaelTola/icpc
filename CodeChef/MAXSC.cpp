#include <bits/stdc++.h>
 
using namespace std;
 
int m[710][710];
int n;
 
int bs(int x, int cur) {
    int a = 0;
    int b = n;
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(m[x][mid] >= cur) b = mid;
        else a = mid;
    }
    return m[x][a];
}
 
int main(){
    
    int t;
    scanf("%d", &t);
 
    while(t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x;
                scanf("%d", &x);
                m[i][j] = x;
            }
            sort(m[i],m[i] + n);
        }
        long long ans = 0;
        int last = INT_MAX;
        bool found = 1;
        for (int i = n - 1; i >= 0; i--) {
            int cur = bs(i,last);
            if(cur > last) found = 0;
            ans += cur;
            last = cur;
        }
        if(!found) puts("-1");
        else printf("%lld\n", ans);
    }
    return 0;
}
