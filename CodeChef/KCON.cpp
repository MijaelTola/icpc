#include <bits/stdc++.h>

using namespace std;

int v[100010];
vector<long long> a;
int main(){
    
    int t;
    scanf("%d",&t);

    while(t--) {
        a.clear();
        int n,k;
        scanf("%d %d",&n,&k);
        bool p = 0;
        bool nn = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d",v + i);
            if(v[i] >= 0) p = 1;
            if(v[i] < 0) nn = 1;
        }

        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j)
                a.push_back(v[j]);
        }
        
        long long ans = 0LL;
        long long sum = 0ll;
        for (int i = 0; i < (int)a.size(); ++i){
            sum += a[i];
            sum = max(sum,0LL);
            ans = max(ans,sum);
        }
        printf("%lld\n",ans);
       /* if(!p) {
            long long ans = INT_MIN;
            for (int i = 0; i < n; ++i) {
                ans = max(ans,(long long)v[i]);
            }
            printf("%lld\n",ans);
            continue;
        }
        long long ans = 0;
        long long sum = 0;
        long long a = 0;
        for (int i = 0; i < n; ++i) {
            sum += v[i];
            a += v[i];
            sum = max(sum,0LL);
            ans = max(ans,sum);
        }
        if(!nn) ans *= k;
        a = max(a * k, ans);
        ans = max(a,ans);
        int pos = 0;
        long long ans2 = 0;
        while(v[pos] >= 0 and pos < n) {
            ans2 += v[pos];
            pos++;
        }
        int pos2 = n - 1;
        long long ans3 = 0;
        while(v[pos2] >= 0 and pos2 >= pos) {
            ans3 += v[pos2];
            pos2--;
        }
        if(k > 1) ans2 += ans3;
        else ans2 = max(ans2,ans3);
        printf("%lld\n",max(ans,ans2));*/
    }
    return 0;
}

