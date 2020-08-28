#include <bits/stdc++.h>

using namespace std;

int n;
double dp[10010];
double ds[] = {1.0, 0.50, 0.25, 0.25, 0.25, 0.25};
vector<pair<int,double> > v;

double f(int pos) {
    if(pos == n) return 0;
    double &ans = dp[pos];
    if(ans != -1) return ans;
    ans = 1e15;
    double sum = 0;
    int p = 0, t = 0;
    for (int i = pos; i < min(pos + 6, n); ++i) {
        if(t < 120) {
            sum += v[i].second * ds[p++];
            ans = min(ans, f(i + 1) + sum);
            t += v[i].first;
        }
    }

    return ans;
}

int main() {

    for (int i = 0; i < 10010; ++i) dp[i] = -1.0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        v.push_back(make_pair(x,y));
    }

    printf("%.2lf\n", f(0));
    return 0;
}

