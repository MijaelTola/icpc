#include <bits/stdc++.h>

using namespace std;

int v[100010];
long long l[100010];
pair<int,int> b[100010];
int n,s;


bool ver(int k) {
    for (int r = 0; r < n; ++r) {
        bool flag = 0;
        int i = b[r].second;

        for (int j = i + 1; j <= min(i + k,n - 1); ++j) 
            flag |= v[j] < v[i];

        long long mx = 0;
        if(flag) {
            for (int j = i + 1; j <= min(i + k,n - 1); ++j) 
                if(v[j] < v[i]) mx = max(mx,l[j]);
        }
        
        flag = 0;
        
        for (int j = max(i - k,0); j < i; j++) 
            flag |= v[j] < v[i];

        if(flag) {
            for (int j = max(i - k,0); j < i; j++) 
                 if(v[j] < v[i]) mx = max(mx,l[j]);
        }
        l[i] = mx + 1;
    }

    long long sum = 0;
    for (int i = 0; i < n; ++i) 
        sum += l[i];
    return sum <= s;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &s);
        for (int i = 0; i < n; ++i) {
            scanf("%d", v + i);
            b[i].first = v[i];
            b[i].second = i;
        }
        sort(b, b + n);
        
        int ans = 0;
        for (int k = 0; k <= n; ++k) 
            ans += ver(k);
            
        printf("%d\n",ans);
        /*int a = -1;
        int b = n + 1;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            memset(l,0, sizeof l);
            if(ver(mid)) a = mid;
            else b = mid;
        }
        printf("%d\n", a + 1);*/
    }
    return 0;
}

