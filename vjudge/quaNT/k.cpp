#include <bits/stdc++.h>

using namespace std;

int n;
int v[10000010];
int a[10000010];

int main() {

    scanf("%d", &n);
    
    long long mn = LLONG_MAX;
    pair<long long, long long> ans = {-1, -1};
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if(v[x] and x < mn) {
            mn = x;
            ans = {a[x], i};
        }
        v[x] = x;
        a[x] = i;
    }



    for (int x = 1; x <= 10000000; ++x) {
        vector<long long> s,t;
        for (int i = x; i <= 10000000; i += x) {
            if(v[i]) {
                s.push_back(i);
                t.push_back(a[i]);
                if((int)s.size() == 2) break;
            }
        }
        if(s.size() != 2) continue;
        
        long long gcd = (s[0] * s[1]) / x;
        
        if(gcd < mn) {
            mn = gcd;
            ans = {min(t[0],t[1]), max(t[0],t[1])};
        }
    }

    printf("%lld %lld\n", ans.first + 1, ans.second + 1);

    return 0;
}

