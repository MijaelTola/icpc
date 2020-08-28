#include <bits/stdc++.h>

using namespace std;

int n,x;
int v[15];

int f(int mask, int left, vector<int> vv) {
    if(mask == (1 << n) - 1) {
        for (int l: vv)
            cout << (char)(l + 'A') << " ";
        cout << " " << left << "\n";
        return left == 0;
    }
    int ans = 0;
    int cur = 0;

    for (int i = 0; i < n; ++i) 
        cur += !(mask & (1 << i));

    for (int i = 0; i < n; ++i) {
        if(mask & (1 << i)) continue;
        int p = 1;
        while(left - cur * p >= 0) p++;
        p--;
        ans += f(mask | (1 << i), left - cur *p,vv);     
    }
    return ans;
}

int main() {

    scanf("%d %d", &n, &x);
    
    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);
    
    int id = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i] > mx) {
            mx = v[i];
            id = i;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        x -= mx - v[i];
        v[i] += (mx - v[i]);
    }

    printf("%d\n", f(0, x,{}));
    return 0;
}

