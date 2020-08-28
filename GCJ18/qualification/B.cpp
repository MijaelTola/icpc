#include <bits/stdc++.h>

using namespace std;

int even[100010];
int odd[100010];
int v[100010];
int main(){

    int t;
    scanf("%d",&t);
    
    for (int k = 1; k <= t; ++k) {
        int n; scanf("%d",&n);
        int e = 0;
        int o = 0;
        for (int i = 0; i < n; ++i) {
            int x; scanf("%d",&x);
            if(i & 1) odd[o++] = x;
            else even[e++] = x;
        }
        sort(odd, odd + o);
        sort(even, even + e);
        int pos = 0;
        for (int i = 0; i < n; i += 2) 
            v[i] = even[pos++];
        pos = 0;
        for (int i = 1; i < n; i += 2)
            v[i] = odd[pos++];

        int id = -1;
        for (int i = 1; i < n; ++i) {
            if(v[i] < v[i - 1]) {
                id = i;
                break;
            }
        }
        printf("Case #%d: ",k);
        if(id == -1) puts("OK");
        else printf("%d\n",id - 1);

    }
    return 0;
}

