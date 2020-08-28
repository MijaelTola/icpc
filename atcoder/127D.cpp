#include <bits/stdc++.h>

using namespace std;

int n,m,x,b,c;
priority_queue<pair<int,int> > q;

int main() {
    
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        q.push({-x, 1});
    }

    while(m--) {
        scanf("%d %d", &b, &c);
        
        int cur = 0;
        int last = -1;
        while(!q.empty() and cur < b and -q.top().first < c) {
            cur += q.top().second;
            last = q.top().first;
            q.pop();
        }
        
        if(cur > b) 
            q.push({last, cur - b});
        
        q.push({-c, min(b, cur)});
    }

    long long ans = 0;
    
    while(!q.empty()) {
        ans += -1ll*q.top().first * q.top().second;
        q.pop();
    }

    cout << ans << "\n";
    return 0;
}

