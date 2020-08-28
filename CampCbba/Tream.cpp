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
    int key,priority;
    node *l = NULL,*r = NULL;
    node(int key) : key(key){
        priority = (rand()*rand()%rand())^rand(); 
    }
};
int A[1010];
struct Treap{
    
    void merge(node *&t, node *l,node * r){
        if(l == NULL) {t = r;}
        else if(r == NULL){t = l;}
        else if(l->priority > r->priority){
            merge(l->r,l->r,r); t = l;
        }else{
            merge(r->l,l,r->l); t = r;
        }
    }

    void split(node *t,node *&l,node *&r, int key){
        if(t == NULL){l = r = NULL; return;}
        if(t->key >= key){
            split(t->l,l,t->l,key); r = t;
        }else{
            split(t->r,t->r,r,key); l = t;
        }
    }
    
    node *root = NULL;
    
    void insert(node *&t,int key){
        node *X = new node(key),*l,*r;
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
    void dfs(node* v){
        if(v == NULL) return;
        dfs(v->l); cout << v->key << " ";
        dfs(v->r);
    }

    void print(){dfs(root);}
    void erase(int k){remove(root,k);}
    void insert(int k){insert(root,k);}
    Treap(int n){
        for (int i = 0;i<n;++i)
            insert(root,A[i]);
    }
    
};
int main(){
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];
    Treap T(n);
    T.print();
    while(1){
        int x; cin >> x;
        if(x == 1){
            int y; cin >> y;
            T.insert(y);
        }
        if(x == 2){
            int y; cin >> y;
            T.erase(y);
        }
        T.print();
    }
    return 0;
}

