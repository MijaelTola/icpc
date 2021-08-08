
#include <bits/stdc++.h>

using namespace std;

int n,k;
map<int,int> pos;
int tree[1000010];
int ans[1000010];
int b[1000010];

typedef struct Node{
    int s, e, val, pos;
    bool operator<(const Node& n) const{
        if(e != n.e) return e < n.e;
        return val > n.val;
    }
    Node(){};
    Node(int ss, int ee, int v, int p){
        s = ss, e = ee, val = v, pos = p;
    }
}Node;


vector<Node> v;

void update(int x, int val){
    while(x <= n){
        tree[x] += val;
        x += x & -x;
    }
}

int query(int x){
    int ret = 0;
    while(x > 0){
        ret += tree[x];
        x -= x & -x;
    }
    return ret;
}
int main() {

   ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> k;


    map<int, vector<int> > mp;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        b[i] = x;
        mp[x].push_back(i);
        v.push_back(Node(i, i, x, -1));
    }

    

    for (int i = 0; i < n; ++i) {
        int x = lower_bound(mp[b[i]].begin(), mp[b[i]].end(), i) - mp[b[i]].begin();
        int y = -1;
        if(x >= 0 and x < (int)mp[b[i]].size() and x + k - 1 >= 0 and x + k - 1 < (int)mp[b[i]].size()) {
            y = mp[b[i]][x + k - 1];
            int l = mp[b[i]][x];
            v.push_back(Node(l, y, 0, i));
        }
    }

    sort(v.begin(), v.end());
    
    int res = 1e9;
    for(int i = 0;i < (int)v.size(); i++){
        if(v[i].val == 0)
            res = min(res, query(v[i].e) - query(v[i].s - 1));
        else {
            
            if(pos[v[i].val] != 0)
                update(pos[v[i].val], -1);
 
            update(v[i].s, 1);
            pos[v[i].val] = v[i].s;
        }
    }

    if(res == 1e9) cout << "-1\n";
    else cout << res - 1 << "\n";

    return 0;
}

