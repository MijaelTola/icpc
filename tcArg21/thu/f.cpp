#include <bits/stdc++.h>

using namespace std;

struct node{
    int l,r,left,right,lazy,andans;
};

vector<node> tree(2000000);
int n,m,num,root;
void build(int &x,int l,int r){
    x=++num;
    tree[x].l=l;
    tree[x].r=r;
    if (l==r) return ;
    int mid=(l+r)>>1;
    build(tree[x].left,l,mid);
    build(tree[x].right,mid+1,r);
}

void update(int x){
    int l=tree[x].left,r=tree[x].right;
    tree[x].andans=tree[l].andans&tree[r].andans;
}
void pushdown(int x){
    if (!tree[x].lazy) return ;
    int l=tree[x].left,r=tree[x].right;
    tree[l].lazy|=tree[x].lazy;tree[r].lazy|=tree[x].lazy;
    tree[l].andans|=tree[x].lazy;tree[r].andans|=tree[x].lazy;
    tree[x].lazy=0;
}

void insert(int x,int l,int r,int v){
    if (l<=tree[x].l&&r>=tree[x].r){
        tree[x].andans|=v;
        tree[x].lazy|=v;
        return;
    }
    int mid=(tree[x].l+tree[x].r)>>1;
    pushdown(x);
    if (l<=mid) insert(tree[x].left,l,r,v);
    if (r>mid) insert(tree[x].right,l,r,v);
    update(x);
}

int query(int x,int l,int r){
    if (l<=tree[x].l&&r>=tree[x].r) return tree[x].andans;
    int mid=(tree[x].l+tree[x].r)>>1;pushdown(x);
    int tmp=(1 << 30) - 1;
    if (l<=mid) tmp&=query(tree[x].left,l,r);
    if (r>mid) tmp&=query(tree[x].right,l,r);
    return tmp;
}

int main(){
    cin >> n >> m;

    build(root,1,n);
    vector<tuple<int,int,int> > v;

    for (int i = 0; i < m; ++i) {
        int l,r,z;
        cin >> l >> r >> z;
        v.push_back({l,r,z});
        insert(root,l,r,z);
    }

    for (auto [l,r,z]: v) {
        int tmp=query(root, l, r);
        if (tmp!=z)
            return puts("NO"), 0;
    }
    cout << "YES\n";
    for (int i=1;i<=n;++i) 
        cout << query(root, i,i) << " ";
    cout << "\n";
    return 0;
}

