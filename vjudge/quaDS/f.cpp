#include <bits/stdc++.h>

using namespace std;

int n,m;
int v[200010];
int ans[200010];
bool vis[200010];

vector<pair<int,int> > b;
vector<tuple<int,int,int> > sorted;

struct SegmentTree {
    vector<int> st;
    int n;
    SegmentTree(){};
    
    void build(int _) {
        n = _;
        st.resize(3 * n);
    }

    int ope(int a, int b) {
        return max(a, b);
    }

    void update(int pos,int value){
        for (st[pos+=n]= value; pos > 1; pos>>=1)
            st[pos>>1] = ope(st[pos], st[pos^1]);
    }

    int query(int l,int r){
        int ans = 0;
        r++;
        for (l += n,r += n; l < r; l >>= 1, r >>= 1){
            if(l&1) ans = ope(ans, st[l++]);
            if(r&1) ans = ope(ans, st[--r]);
        }
        return ans;
    }
};

int main() {

    SegmentTree st;

    scanf("%d %d", &n, &m);
    
    st.build(m);

    for (int i = 0; i < n; ++i) {
        scanf("%d", v + i);
    }
    
    for (int i = 0; i < m; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        b.push_back(make_pair(x,y));
        st.update(i, y);
    }
    
    int flag = 1, first = 1;
    
    int l = 0, r = n - 1;
    int cur = n - 1;

    for (int i = 0; i < m; ++i) {
        int cur = b[i].second;
        if(i + 1 < m && cur <= st.query(i + 1, m)) continue;
        int t = b[i].first;
        if(first) {
            sort(v, v + cur);
            l = 0, r = cur - 1;
            first = 0;
            flag = t;
            sorted.push_back({l,r, flag});
            continue;
        }
        if(flag == t) continue;
        if(flag == 2) l = r - cur + 1;
        else r = l + cur - 1;
        flag = t;
        sorted.push_back({l,r, flag});
    }
    int dl = 0, dr = n - 1, last = 1;
    cur = n - 1;
    for (auto t: sorted) {
        tie(l,r,flag) = t;
        if(last == 1) {
            for (int i = dr; i > r; i--, cur--) 
                ans[cur] = v[i];
        } else {
            for (int i = dl; i < l; ++i, cur--) 
                ans[cur] = v[i];
        }
        dl = l, dr = r;
        last = flag;
    }

    tie(l,r,flag) = sorted.back();


    if(flag == 1) {
        for (int i = r; i >= l; i--, cur--) 
            ans[cur] = v[i];
    } else {
        for (int i = l; i <= r; ++i, cur--) 
            ans[cur] = v[i];
    }

    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i]);
    puts("");
    return 0;
}

