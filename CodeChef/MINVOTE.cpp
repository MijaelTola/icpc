#include <bits/stdc++.h>

using namespace std;

int v[100010];
long long da[100010];
int l[100010];
int r[100010];
int dl[100010];
int dr[100010];
int ans[100010];

int main(){
    int t;
    scanf("%d",&t);
    while(t--) {
        memset(l, 0, sizeof l);
        memset(r, 0, sizeof r);
        memset(dr, 0, sizeof dr);
        memset(dl, 0, sizeof dl);
        memset(ans, 0, sizeof ans);
        memset(da, 0,sizeof da);
        int n; scanf("%d",&n);

        for (int i = 0; i < n; ++i) {
            scanf("%d", v + i);
            da[i] = v[i];
            if(i) da[i] += da[i - 1];
        }
        
        for (int i = 0; i < n; ++i) {
            int cur = v[i];
            int a = i;
            int b = n - 1;
            while(b - a > 1) {
                int mid = (a + b) / 2;
                if(abs(da[mid] - da[i]) <= cur) a = mid;
                else b = mid;
            }
            l[i + 1]++;
            dl[a + 1]--;
            a = 0;
            b = i;
            while(b - a > 1) {
                int mid = (a + b) / 2;
                if(abs(da[i - 1] - da[mid - 1]) <= cur) b = mid;
                else a = mid;
            }
            r[i - 1]++;
            dr[b - 1]--;
        }

        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += l[i];
            ans[i] = cur;
            cur += dl[i];
        }
        cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            cur += r[i];
            ans[i] += cur;
            cur += dr[i];
        }
        for (int i = 0; i < n; ++i) 
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}

