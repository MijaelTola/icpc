#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);

    priority_queue<int> a,b;
    long long da = 0, db = 0;
    int ca = 0, cb = 0;

    for (int l = 0, r = n - 1, ini = 1; l <= r; l++,r--, ini++) {
        if(l <= r) {
            int val = ini - v[l];
            if(val >= 0) a.push(val), da += val, ca++; 
            else b.push(val), db += -val, cb++;
        }
    
        if(r > l) {
            int val = ini - v[r];
            if(val >= 0) a.push(val), da += val, ca++;
            else b.push(val), db += -val, cb++;
        }
    }

    long long ans = da + db;

    for (int i = 1; i < 100000; ++i) {
        int cnt = 0;
        while(!b.empty() and b.top() + i >= 0) {
            cnt++;
            db += b.top();
            b.pop();
        }
        ans = min(ans, da + ca + (db - (int)b.size() * i));
        da += cnt;
        ca += cnt;
        cb -= cnt;
    }

    printf("%lld\n", ans);

    return 0;
}

