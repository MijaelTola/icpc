#include <bits/stdc++.h>

using namespace std;

int v[310];
priority_queue<int> q;
int main(){
    
    int n,k;
    scanf("%d %d",&n,&k);

    for (int i = 0; i < n; ++i)
        scanf("%d",v+i);
    
    for (int i = 0; i < k; ++i) q.push(-v[i]);
    int pos = k;
    long long time = 0;
    long long ans = 0;
    while(pos < n){
        int cur = -q.top();
        q.pop();
        time += cur;
        ans += time;
        q.push(-v[pos++]);
    }
    while(!q.empty()){
        int cur = -q.top();
        q.pop();
        time += cur;
        ans += time;
    }
    printf("%lld\n",ans);
    return 0;
}

