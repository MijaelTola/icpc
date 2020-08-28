#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less<int >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

using namespace std;
int v[100010];
int pos[100010];
int marked[100010];
int reals[100010];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int cases;
	cin >> cases;
	while (cases--) {
		int n;
		cin >> n;
		memset(marked, 0, sizeof marked);
		for  (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = 0, u; i < n; i++) {
			cin >> u;
			pos[u] = i;
		}
		for (int i = 0; i < n; i++) {
			reals[i] = pos[v[i]];
			cout << reals[i] << " ";
		}
		cout << endl;
		ordered_set st;
		long long ans = 0LL;
		for (int i = 0; i < n; i++) {
			st.insert(reals[i]);
			cout << (n - i - 1) << " " << reals[i] << " " << st.order_of_key(reals[i]) << endl;
			ans += (min(n - i - 1, int(reals[i] -  st.order_of_key(reals[i]))));
		}
		cout << ans << "\n";
	}
}
