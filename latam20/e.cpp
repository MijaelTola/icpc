#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int ans[N];
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  set <int> s;
  priority_queue < pair <int, int> > q;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    q.push( {a[i], i} );
  }
  memset(ans, 0, sizeof ans);
  s.insert(-1);
  s.insert(n);
  while (!q.empty()) {
    int i = q.top().second;
    q.pop();
    auto le1 = s.lower_bound(i);
    le1--;
    auto ri1 = s.lower_bound(i);
    
    int le = *le1;
    int ri = *ri1;
    cout << i << ' ' << a[i] << ' ' << le << ' ' << ri << endl;
    if (le == -1) {
      ans[le + 1] ++;
      ans[i]--;
    }
    else {
      int d = i - le - 1;
      d/=2;
      ans[i - d]++;
      ans[i]--;
    }
    if (ri == n) {
      ans[i + 1]++;
      ans[n]--;
    }
    else {
      int d = ri - i - 1;
      d/=2;
      ans[i + 1]++;
      ans[i + d]--;
    }
    s.insert(i);
  }
  for (int i = 1; i < n; i++) {
    ans[i] += ans[i - 1];
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  puts("");
  return 0;
}


