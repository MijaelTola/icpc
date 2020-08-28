#include <bits/stdc++.h>

using namespace std;

const int p = 1e9+7;
const int x = 256;
long long vpow[1000010];
int h[1000010];
char s[1000010];

long long getH(int i, int j) {
    int sz = j - i + 1;
    return ((h[i] - (h[j + 1] * vpow[sz]) % p) + p) % p;
}

int main() {
    scanf("%s", s);
    int n = strlen(s);
    vpow[0] = 1;
    for (int i = 1; i <= n; ++i) 
        vpow[i] = ((long long)vpow[i - 1] * (long long )x) % p;

    int hash = 0;
    for (int i = n - 1; i >= 0; i--) {
        hash = ((((long long)hash * x + s[i]) % p) + p) % p;
        h[i] = hash % p;
    }
    
    int a = 0, b = n - 1;
    int ans = 0;

    while(a <= b) {
        if(s[a] == s[b]) {
            if(a != b)ans += 2;
            else ans++;
            a++,b--;
        } else {
            int da = a, db = b;
            bool flag = 0;
            while(da < db) {
                int h1 = getH(a, da);
                int h2 = getH(db, b);
                if(h1 == h2) {
                    ans += 2;
                    flag = 1;
                    break;
                }
                da++,db--;
            }
            a = da + 1, b = db - 1;
            if(!flag) {
                ans++;
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

