#include <bits/stdc++.h>

using namespace std;

bool is[1000010];
vector<int> p;

void build() {
    for (int i = 2; i < 1000010; ++i)  
        for (int j = i + i; j < 1000010; j += i)
            is[j] = 1;
    for (int i = 2; i < 1000010; ++i)
        if(!is[i]) p.push_back(i);
}
long long ans;
void f(long long n) {
    long long id = 0, pf = p[id];
    while(pf * pf <= n) {
        bool flag = 0;
        while(n % pf == 0) {
            n /= pf;
            flag = 1;
        }
        ans += flag;
        pf = p[++id];
    }
    ans += n != 1;
}
int main() {
    build();
    ans = 1;
    long long a,b;
    cin >> a >> b;
    long long g = __gcd(a,b);
    f(g);
    cout << ans << "\n";
    return 0;
}

