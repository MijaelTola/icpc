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
    int mid = (l+r)/2;
    int p1 = query(n->left,l,mid,i,j);
    int p2 = query(n->right,mid+1,r,i,j);
    if(p1 == -1) return p2;
    if(p2 == -1) return p1;
    return p1 + p2;
}

vector<node*> version;
int v[100010];
int a[100010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;

    node *root = new node(NULL,NULL,0);

    build(root,0, n + 10);

    version.push_back(root);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = n - 1; i >= 0; i--) {
        node *nv = new node(NULL,NULL,0);
        update(version.back(), nv, 0, n + 10, a[v[i]], 0);
        node *nv2 = new node(NULL,NULL,0);
        update(nv, nv2, 0, n + 10, i, 1);
        version.push_back(nv2);
        a[v[i]] = i;
    }

    reverse(version.begin(), version.end());
    int q,p = 0;
    cin >> q;

    while(q--) {
        int x,y;
        cin >> x >> y;
        int l = (x + p) % n + 1;
        int k = (y + p) % m + 1;
        l--;

        int a = -1, b = n + 10;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            int cnt = query(version[l],0, n + 10, 0, mid);
            if(cnt >= k) b = mid;
            else a = mid;
        }
        if(query(version[l], 0, n + 10, 0, b) == k) {
            cout << b + 1<< "\n";
            p = b + 1;
        } else {
            cout << 0 << "\n";
            p = 0;
        }
    }

    return 0;
}
