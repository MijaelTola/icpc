#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int maxn = 1e5 + 10;
pair<int,int> h[maxn];
pair<int,int> v[maxn];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, m;
	cin >> n >> m;
	cin >> n >> m;
	for (int i = 0, u, vv; i < n;i++) {
		cin >> u >> vv;
		h[i] = {u, vv};
	}
	sort(h, h + n);
	for (int i = 0, u, vv; i < m;i++) {
		cin >> u >> vv;
		v[i] = {u, vv};
	}
	sort (v, v + m);
	long long ans = (n + 1) * (m + 1);
	
	ordered_set st;
	for (int i = 0; i < n;i++) {
		ans += st.order_of_key(h[i].second);
		st.insert(h[i].second);
	}
	st.clear();
	for (int i = 0; i < m;i++) {
		ans += st.order_of_key(v[i].second);
		st.insert(v[i].second);
	}
	cout << ans << "\n";
	return 0;
}
