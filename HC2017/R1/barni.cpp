#include <bits/stdc++.h>

using namespace std;

#ifdef ACMTUYO
struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#else
struct RTC{};
#define DBG(X)
#endif

#define fast_io() ios_base::sync_with_stdio(false)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
typedef long long int number;
const int maxn = 300 + 10;
int n, m;
int cost[maxn][maxn];
number dp[maxn][maxn];
number oo = LLONG_MAX >> 2LL;
number gao(int day, int has) {
  assert(has >= 0 && has <= n);
  if (day == n + 1) return 0LL;
  number &answer = dp[day][has];
  if (answer != -1LL) return answer;
  answer = oo;
  number cur_cost = 0;
  for (number buy = 0; buy <= m; buy++) {
    int now = has + buy - 1;
    cur_cost += cost[day][buy];
    if (now >= 0) 
      answer = min(answer, gao(day + 1, min(n, now)) + cur_cost + buy * buy);
  }
  return answer;
}
int main() {
  int tc;
  scanf("%d", &tc);
  for (int cs = 1; cs <= tc; cs++) {
    DBG(cs);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++)
        scanf("%d", &cost[i][j]);
      cost[i][0] = 0;
      sort(cost[i], cost[i] + m + 1);
    }
    memset(dp, -1, sizeof(dp));
    printf("Case #%d: %lld\n", cs, gao(1, 0));
  }
  return 0;
}
