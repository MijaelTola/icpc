#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>
#include <string> 
#include <sstream>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
struct node{
    int key,priority,size;
    bool reverse;
    char data;
    int lazy;
    node *l = NULL,*r = NULL;
    node(int key, char data) : key(key), data(data){
        priority = (rand()*rand()%rand())^rand(); 
        reverse = false;
        size = 1;
        lazy = 0;
    }
};
struct Treap{
    
    int size(node *v){return v == NULL ? 0 : v->size;}
    
    void update(node *v){
        if(v == NULL) return;
        v->size = 1 + size(v->l)+size(v->r);
    }
    void pushdown(node *v){
        if(v == NULL)  return;
        if(v->reverse){
            swap(v->l,v->r);
            if(v->l != NULL) v->l->reverse = !v->l->reverse;
            if(v->r != NULL) v->r->reverse = !v->r->reverse;
            v->reverse = false;
        }
        if(v->lazy == 0) return;
        int aux = (v->data - 'a' + v->lazy);
        aux %= ('z' - 'a' + 1);
        aux += 'a';
        v->data = aux;
        if(v->l) v->l->lazy += v->lazy;
        if(v->r) v->r->lazy += v->lazy;
        v->lazy = 0;
    }
    void merge(node *&t, node *l,node * r){
        pushdown(l); pushdown(r);
        if(l == NULL) {t = r;}
        else if(r == NULL){t = l;}
        else if(l->priority > r->priority){
            merge(l->r,l->r,r); t = l;
        }else{
            merge(r->l,l,r->l); t = r;
        }
        update(t);
    }

    void split(node *t,node *&l,node *&r, int key){
        pushdown(t);
        if(t == NULL){l = r = NULL; return;}
        int id = size(t->l)+1;
        if(id > key){
            split(t->l,l,t->l,key); r = t;
        }else{
            split(t->r,t->r,r,key-id); l = t;
        }
        update(t);
    }
    
    node *root = NULL;
    
    void insert(node *&t,char data,int key){
        node *X = new node(key,data),*l,*r;
        split(t,l,t,key);
        split(t,t,r,key+1);
        merge(t,l,X);
        merge(t,t,r);
    }
    
    void remove(node *&t,int key){
        node *l,*rm;
        split(t,l,t,key);
        split(t,rm,t,key+1);
        merge(t,l,t);
    }
    
    //range [l,r]
    void reverse(node *&t,int l, int r){
        node *left= NULL;
        node *right = NULL;
        node *mid = NULL;
        split(t,left,right,r);
        split(left,left,mid,l-1);
        mid->reverse = !mid->reverse;
        merge(t,left,mid);
        merge(t,t,right);
    }
    void change(node *&t, int l, int r, int m, int n){
        node *left = NULL;
        node *second = NULL;
        node *right = NULL;
        split(t,left,right,n);
        split(left,left,second,m-1);
        node *lleft = NULL;
        node *first = NULL;
        node *rright = NULL;
        split(left,lleft,rright,r);
        split(lleft,lleft,first,l-1);
        second->reverse = !second->reverse;
        second->lazy++;
        first->reverse = !first->reverse;
        first->lazy++;
        t = NULL;
        merge(t,lleft,second);
        merge(t,t,rright);
        merge(t,t,first);
        merge(t,t,right);
    }
    void dfs(node* v){
        pushdown(v);
        if(v == NULL) return;
        dfs(v->l); cout << v->data;
        dfs(v->r);
    }

    void print(){dfs(root);}
    void erase(int k){remove(root,k);}
    void insert(int k,char data){insert(root,k,data);}
    void reverse(int x,int y){reverse(root,x,y);}
    void change(int x,int y, int a,int b){change(root,x,y,a,b);};
    Treap(string &t){
        for (int i = 0;i<(int)t.size();++i){
            insert(root,t[i],i);
        }
            
    }
    
};

//:::::::::::::::::ROPE PROBLEM:::::::::::::::::::::::::
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--){
        string x; cin >> x;
        Treap T(x);
        int q; cin >> q;
        while(q--){
            int l,r,n,m;  cin >> l >> r >> n >> m;
            T.change(l,r,n,m);
        }
        T.print();
        cout <<"\n";
    }
    return 0;
}

