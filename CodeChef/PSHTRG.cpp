#include <bits/stdc++.h>

using namespace std;

int v[100010];

struct node {
    vector<int> mx;
    node * left;
    node * right;
    node () {
        left = NULL;
        right = NULL;
    }
};

struct SegmentTree {
    node * root;

    void build(node * current, int l,int r) {
        if(l == r)  {
            current->mx = {v[l]};
            return;
        }
        int mid = (l + r) / 2;
        current->left = new node();
        current->right = new node();
        build(current->left, l, mid);
        build(current->right,mid + 1, r);
        int pl = 0;
        int pr = 0;
        while(current->mx.size() < 90 and 
                (pl < (int)current->left->mx.size() 
                 or pr < (int)current->right->mx.size())) {
            int curl = 0;
            int curr = 0;
            if(pl < (int)current->left->mx.size()) 
                curl = current->left->mx[pl];
            if(pr < (int)current->right->mx.size()) 
                curr = current->right->mx[pr];
            if(curl > curr) {
                current->mx.push_back(curl);
                pl++;
            }else {
                current->mx.push_back(curr);
                pr++;
            }
        }

    }

    vector<int> query(node * current, int l, int r, int i, int j) {
        if(i > r or j < l) return {};
        if(i <= l and r <= j) {return current->mx;}
        if(l == r) return {};
        int mid = (l + r) / 2;
        vector<int> left = query(current->left,l, mid, i ,j);
        vector<int> right = query(current->right,mid + 1, r, i, j);
        vector<int> cur;
        int pl = 0;
        int pr = 0;
        while((int)cur.size() < 90 and 
                (pl < (int)left.size() 
                 or pr < (int)right.size())) {
            int curl = 0;
            int curr = 0;
            if(pl < (int)left.size()) 
                curl = left[pl];
            if(pr < (int)right.size()) 
                curr = right[pr];
            if(curl > curr) {
                cur.push_back(left[pl]);
                pl++;
            }else {
                cur.push_back(right[pr]);
                pr++;
            }
        }
        return cur;
    }

    void update(node * current , int l, int r, int pos, int val) {
        if(l == r) {
            current->mx[0] = val;
            v[l] = val;
            return;
        }
        int mid = (l + r) / 2;

        if(l <= pos and pos <= mid) update(current->left, l, mid, pos, val);
        else update(current->right,mid + 1, r, pos, val);

        int pl = 0;
        int pr = 0;
        current->mx.clear();
        while(current->mx.size() < 90 and 
                (pl < (int)current->left->mx.size() 
                 or pr < (int)current->right->mx.size())) {
            int curl = 0;
            int curr = 0;
            if(pl < (int)current->left->mx.size()) 
                curl = current->left->mx[pl];
            if(pr < (int)current->right->mx.size()) 
                curr = current->right->mx[pr];
            if(curl > curr) {
                current->mx.push_back(current->left->mx[pl]);
                pl++;
            }else {
                current->mx.push_back(current->right->mx[pr]);
                pr++;
            }
        }

    }

    long long query(int x,int y,int n) {
        x--,y--;
        vector<int> ans = query(root, 0, n, x, y);
        for (int i = 0; i < (int)ans.size() - 2; ++i) {
            long long a = ans[i];
            long long b = ans[i + 1];
            long long c = ans[i + 2];
            if(a + b > c and a + c > b and b + c > a) {
                return a + b + c;
            }
        }
        return 0;
    }

    void update(int x,int y, int n) {
        x--;
        update(root, 0, n, x, y);
    }
    void start(int x, int y) {
        root = new node();
        build(root,x,y);
    }
    SegmentTree() {root = NULL;}
};
int main(){
    int n,q; 
    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);
    SegmentTree ST;
    ST.start(0, n - 1);

    while(q--) {
        int c,x,y;
        scanf("%d %d %d", &c, &x, &y);

        if(c == 2) printf("%lld\n", ST.query(x,y,n - 1));
        else ST.update(x,y,n - 1);
    }
    return 0;
}

