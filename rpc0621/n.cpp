#include <bits/stdc++.h>

using namespace std;
int head[500010];
int tail[500010];
int nxt[500010];
int pre[100010];
int main() {
  int n;
  cin >> n;
  vector<int>v(n);
  for (int &x: v){cin >> x;--x;}
  set<int>st;
  for (int i = 0; i <= n; i++)head[i] = tail[i] = nxt[i] = pre[i] = i;
  for (int i = 0; i < n - 1; i++) {
    int possible = 0;
    while (st.count(v[i]) || head[v[i]] == i) {
      v[i] = nxt[possible];
      possible = v[i] + 1;
    }
    st.insert(v[i]);
    nxt[pre[v[i]]] = nxt[v[i] + 1];
    pre[nxt[v[i] + 1]] = pre[v[i]];
    head[tail[i]] = head[v[i]];
    tail[head[v[i]]] = tail[i];
  }
  v[n - 1] = nxt[0];
  for (int i = 0; i < (int)v.size(); ++i) {
      cout << v[i] + 1;
      if(i + 1 < (int)v.size())
          cout << " ";
  }
  cout << endl;
  return 0;
}
