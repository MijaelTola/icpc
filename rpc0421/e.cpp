#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

using namespace std;


int main() {

    int n;
    cin >> n;

    vector<pair<int,int> > v;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back({x, i});
    }

    sort(v.rbegin(), v.rend());
    ordered_set s;

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = s.order_of_key(v[i].second);
        int r = i - l;
        s.insert(v[i].second);
        ans += min(l, r);
    }
    cout << ans << "\n";
    return 0;
}


