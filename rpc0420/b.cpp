#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k; scanf("%d %d", &n, &k);
  vector <int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  vector <int> nxt(n, -1), ult(k + 1, -1);
  for (int i = n - 1; i >= 0; i--) {
    nxt[i] = ult[a[i]];
    ult[a[i]] = i;
  }
  stack <int> s;
  vector <bool> inS(k + 1, 0);
  for (int i = 0; i < n; i++) {
    if (s.empty()) {
      s.push(i);
      inS[a[i]] = 1;
    }
    else {
      if (inS[a[i]]) continue;
      else {
        while (s.size() > 0 && a[i] < a[s.top()] && nxt[s.top()] != -1) {
          inS[a[s.top()]] = 0;
          s.pop();
        }
        s.push(i);
        inS[a[i]] = 1;
      }
    }
  }
  vector <int> ans;
  while (!s.empty()) ans.push_back(s.top()), s.pop();
  for (int i = ans.size() - 1; i >= 0; i--) printf("%d ", a[ans[i]]); 
  puts("");
  //3 2 1 3
  return 0;
}
