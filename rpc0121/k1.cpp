
#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    int data;
    node *left, *right;
    node () {}
    node (node *l, node *r, int _) {
        left = l;
        right = r;
        val = _;
    }
};

void build(node *n, int l, int r) {
    if(l == r) {
        n->val = 0;
        return;
    }
    int mid = (l + r) / 2;
    n->left = new node(NULL, NULL, 0);
    n->right = new node(NULL, NULL, 0);
    build(n->left,l, mid);
    build(n->right,mid + 1, r);
    n->val = n->left->val + n->right->val;
}

void update(node *last, node *cur, int l, int r, int pos, int x) {
    if(l == r) {
        cur->val = x;
        return;
    }
    int mid = (l + r) / 2;
    if(pos <= mid) {
        cur->right = last->right;
        cur->left = new node(NULL, NULL, 0);
        update(last->left, cur->left, l, mid, pos, x);
    } else {
        cur->left = last->left;
        cur->right = new node(NULL, NULL, 0);
        update(last->right, cur->right, mid + 1, r, pos, x);
    }
    cur->val = cur->right->val + cur->left->val;
}

int query(node *n, int l, int r, int i, int j) {
    if(i > r or j < l) return -1;
    if(i <= l and r <= j) return n->val;
    int mid = (l + r) / 2;
    int p1 = query(n->left,l,mid,i,j);
    int p2 = query(n->right,mid+1,r,i,j);
    if(p1 == -1) return p2;
    if(p2 == -1) return p1;
    return p1 + p2;
}

int readInt(){
    char r;
    bool start=false,neg=false;
    int ret=0;
    while(true){
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(!neg)
        return ret;
    else
        return -ret;
}

vector<node*> version;
int v[1000010];
map<int,int> a;

int main() {

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,k;
    cin >> n >> k;
    node *root = new node(NULL,NULL,0);

    build(root,0, n + 1);

    version.push_back(root);

    map<int, vector<int> > mp;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mp[v[i]].push_back(i);
    }

    for (int i = n - 1; i >= 0; i--) {
        node *nv = new node(NULL,NULL,0);
        update(version.back(), nv, 0, n + 1, a[v[i]], 0);
        node *nv2 = new node(NULL,NULL,0);
        update(nv, nv2, 0, n + 1, i, 1);
        version.push_back(nv2);
        a[v[i]] = i;
    }

    reverse(version.begin(), version.end());

    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        int x = lower_bound(mp[v[i]].begin(), mp[v[i]].end(), i) - mp[v[i]].begin();
        int y = -1;
        if(x + k - 1 < (int)mp[v[i]].size()) {
            y = mp[v[i]][x + k - 1];
            int l = mp[v[i]][x];
            ans = min(ans, query(version[l], 0, n + 1, l, y) - 1);
        }
    }

    if(ans == 1e9) ans = -1;

    cout << ans<< "\n";

    return 0;
}

