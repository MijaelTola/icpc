 #include <bits/stdc++.h>
#define ll long long
 
using namespace std;

const ll ZERO = 10;
const ll LIM = 1e9 + 1000;
 
unordered_map<ll, unordered_map<ll, ll> > tree;

void update(int n_map, ll id) {
  for(ll i = id; i < LIM; i = i + (i & -i)) {
    tree[n_map][i]++;
  }
}

ll query(int n_map, ll id) {
  ll ans = 0;
  for(ll i = id; i > 0; i = i - (i & -i)) {
    ans = ans + tree[n_map][i];
  }
  return ans;
}

ll _query(ll n_map, ll L, ll R) {
  return query(n_map, R + ZERO) - query(n_map, L - 1 + ZERO);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n, k;
  while(cin >> n >> k) {
    tree.clear();
    vector<tuple<int, int, int> > A; A.clear();
    unordered_map<int,bool> mp;
    for(int i = 0; i < n; i++) {
      int x, r, q;
      cin >> x >> r >> q;
      mp[q] = 1;
      A.push_back({r, x, q});
    }
    sort(A.rbegin(), A.rend());
    ll ans = 0;
    for(int i = 0; i < n; i++) {
      int x, r, q;
      tie(r, x, q) = A[i];
      for(ll j = q - k; j <= q + k; j++) {
        if(!mp[j]) continue;
        ans = ans + _query(j, max((ll) (x - r), 0LL), min((ll) (x + r), LIM));
      }
      update(q, x + ZERO);
    }
    cout << ans << "\n";
  }
  return 0;
} 

