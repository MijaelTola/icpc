#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

using namespace std;

struct event {
	int l, r, x, type, idx;
	event(int _, int __, int ___, int ____, int _____) {
		l = _, r = __, x = ___, type = ____; idx = _____;
	}
	bool operator < (const event &other) {
		if (x == other.x)return r < other.r;
		return x < other.x;
	}
};
vector<event>v;
int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int n;
	cin >> n;
	for (int  i = 0, l, r; i < n;i++) {
		cin >> l >> r;
		v.emplace_back(l, r, l, 0, i);
		v.emplace_back(l, r, r, 1, i);
	}
	
	set<int>st;
	vector<int>ans;
	sort(v.begin(), v.end());
	for (auto e: v) {
		int l = e.l, r = e.r, x = e.x, type = e.type, idx = e.idx;
		if(type == 0) continue;
		//cout << l << " " << r << " " << x << " " << type << endl;
		int k = *st.lower_bound(l);
		if (st.lower_bound(l) == st.end() || k > r) {
			st.insert(r);
		}
	}
	cout << st.size() << "\n";
	for (auto u:st)cout << u  << " ";
}
