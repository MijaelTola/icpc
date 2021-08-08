#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
using namespace std;

int main() {
    
    
    int t;
    cin >> t;

    vector<int> ans;

    for (int k = 0; k < t; ++k) {
        int n;
        cin >> n;

        vector<int> v(n);
        vector<int> mxx(n + 10);
        ordered_set s;
        
        for (auto &x: v)
            cin >> x;

        int mx = -1;

        for (int i = n - 1; i >= 0; i--) {
            mx = max(mx, v[i]);
            mxx[i] = mx;
        }

        bool flag = 0;

        auto check = [&] (int l, int r) {
            return s.order_of_key(r) - s.order_of_key(l);
        };

        for (int i = 0; i < n - 1; ++i) {
            if(mxx[i + 1] > v[i]) {
                if(check(mxx[i + 1], v[i]) > 0) {
                    flag = 1;
                    break;
                }
            }
            s.insert(v[i]);
        }

        if(flag) ans.push_back(k + 1);
    }

    cout << ans.size() << "\n";

    for (auto x: ans)
        cout << x << "\n";
    return 0;
}

