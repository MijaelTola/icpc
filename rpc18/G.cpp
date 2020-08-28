#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> map_t;

int v[100010];
int main() {
    map_t s;
    int n,m;
    cin >> n >> m;
    while(m--) {
        int team,penalty;
        cin >> team >> penalty;
        map_t::iterator it;
        int val = v[team];
        int pos = s.order_of_key(val);
        cout << val << " " << pos << "\n";
        it = s.find_by_order(pos);
        cout << pos << "\n";
        if(pos) s.erase(it);
        s.insert(val + penalty);
        v[team] += penalty;
        for (int p: s) cout << p << " |\n";
    }
    return 0;
}
