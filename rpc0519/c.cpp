#include <bits/stdc++.h>

using namespace std;

int a[500010];
int b[500010];
multiset<int> st;
int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) 
        cin >> a[i];

    for (int i = 0; i < m; ++i)
        cin >> b[i];
    
    sort(a, a + n);
    sort(b, b + m);
    
    priority_queue<pair<int,pair<int,int> > > q;

    for (int i = 0; i < n - 1; i++) 
        q.push({-abs(a[i] - a[i + 1]), {i, i + 1}});
    
    while((int)st.size() < m and !q.empty()) {
        int val = -q.top().first;
        int id = q.top().second.first;
        int pos = q.top().second.second;
        q.pop();
        st.insert(val);
        pos++;
        if(pos < n){
            int nval = abs(a[id] - a[pos]);
            q.push({-nval, {id, pos}});
        }
        
    }
    
    for (int i = 0; i < m; ++i) {
        if(st.empty()) return cout << "no\n",0;
        auto it = st.upper_bound(b[i]);
        it--;
        if(it == st.end() or *it > b[i]) return cout << "no\n",0;
        st.erase(it);
    }
    cout << "yes\n";
    return 0;
}

