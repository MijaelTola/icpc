//problema j
#include <bits/stdc++.h>

#define pi acos(-1)

using namespace std;

int n,m;
int v[110];
double dp[110][110];
double dis[110][110];
vector<int> type[110];

double f(int pos, int last) {
    if(pos == n) return 0;
    double &ans = dp[pos][last];
    if(ans != -1) return ans;
    ans = 1e9;
    for (int k: type[v[pos]]) ans = min(ans, f(pos + 1, k) + dis[last][k]);
    return ans;
}

int main() {
    for (int i = 0; i < 110; ++i)
        for (int j = 0; j < 110; ++j)
            dp[i][j] = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);
    
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int x; 
        scanf("%d", &x);
        type[x].push_back(i);
    }

    auto get = [&] (int i, int j) {
        if(i > j) swap(i, j);
        int k = min(j - i, m - (j - i));
        double theta = k * (2 * pi / m);
        return 2 * sin(theta / 2);
    };
    
    for (int i = 0; i < m; ++i) 
        for (int j = 0; j < m; ++j)
            dis[i][j] = get(i,j);

    double ans = 1e9;

    for (int k: type[v[0]]) {
        ans = min(ans, f(0, k));
    }


    printf("%.6lf\n", ans + 1);

    return 0;
}
