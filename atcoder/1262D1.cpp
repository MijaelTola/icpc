#include <bits/stdc++.h>

using namespace std;

int n,m;
int v[110];
long long dp[110][110];
int k,pos;

long long f(int pos, int dk) {
    if(pos == n) {
        if(dk == k) return 0;
        return -1e15;
    }
    if(dk == k) return 0;
    long long &ans = dp[pos][dk];
    if(ans != -1) return ans;
    ans = -1e5;

    for (int i = pos; i < n; ++i) 
        ans = max(ans, f(i + 1, dk + 1) + v[i]);

    return ans;
}

vector<int> a;
void r(int pos, int dk) {
    if(pos == n or dk == k) return;
    long long ans = -1e15;
    int id = -1;
    for (int i = pos; i < n; ++i) {
        if(f(i + 1, dk + 1) + v[i] > ans) {
            ans = f(i + 1, dk + 1) + v[i];
            id = i;
        } else if(f(i + 1, dk + 1) + v[i] > ans and v[i] < v[id]) {
            ans = f(i + 1, dk + 1) + v[i];
            id = i;
        }
    }

    a.push_back(v[id]);
    r(id + 1, dk + 1);
}

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);

    scanf("%d", &m);

    while(m--) {
        memset(dp, -1, sizeof dp);
        a.clear();
        scanf("%d %d", &k, &pos);
        f(0, 0);
        r(0, 0);
        printf("%d\n", a[pos - 1]);
    }
    return 0;
}

