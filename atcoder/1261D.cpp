#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n,m,x,y;
priority_queue<pair<int,int> > v;
vector<tuple<int,int,int> > q;
vector<pair<int,int> > ans;
int a[200010];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        a[i] = x;
        v.push({x, -i});
    }
    

    scanf("%d", &m);
    

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        q.emplace_back(x,y,i);
    }
    
    sort(q.begin(), q.end());

    ordered_set s;
    
    for (int i = 0; i < m; ++i) {
        int k = get<0>(q[i]);
        int pos = get<1>(q[i]);
        int j = get<2>(q[i]);
        
        while ((int)s.size() < k) {
            s.insert(-v.top().second);
            v.pop();
        }
        
        ans.emplace_back(j, a[*s.find_by_order(pos - 1)]);
        
    }

    sort(ans.begin(), ans.end());

    for (auto p: ans)
        printf("%d\n", p.second);
    return 0;
}

