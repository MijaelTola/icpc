#include <bits/stdc++.h>

using namespace std;

int v[100010];
int a[1000010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(a,-1,sizeof a);
        int n;
        scanf("%d",&n);
        for (int i = 0; i < n; ++i)
            scanf("%d",v + i);
        int ini = 0;
        int ans = 1;
        
        for (int i = 0; i < n; ++i){
            int cur = v[i];
            int last = a[cur];
            if(last >= ini){
                ans = max(ans,i - ini);
                ini = last + 1;
            }
            a[cur] = i;
        }
        printf("%d\n",ans);
    }
    return 0;
}

