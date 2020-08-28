//THIS IS AN IMPLICIT BINARY SEARCH TREE WITH SPLAYS
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

using namespace std;

typedef long long ll;
	
struct Vertex{
	int key;
	char data;
	int size;
	int lazy;
	bool reverse;
	Vertex* left;
	Vertex* right;
	Vertex* parent;
	Vertex(){size = 1;left = NULL;right = NULL;lazy = 0; reverse = false;}
	
	Vertex(int k,int d){
	    key = k;
	    data = d;
        size = 1;
        left = NULL;
        right = NULL;
        parent = NULL;
        reverse = false;
        lazy = 0;
	}
	
};


//problem can be solve by implicit binary search trees ROPES
//A rope is a string that is manipulated on a tree
struct rope{
	rope(){}
	void update(Vertex* v){
	    if(v == NULL) return;
	    v->size = (v->left != NULL ? v->left->size : 0) + (v->right != NULL ? v->right->size: 0)+1;
	    if(v->left != NULL) v->left->parent = v;
	    if(v->right != NULL) v->right->parent = v;
	}

	void small_rotation(Vertex* v) {
	  Vertex* parent = v->parent;
	  if (parent == NULL) {
	    return;
	  }
	  Vertex* grandparent = v->parent->parent;
	  if (parent->left == v) {
	    Vertex* m = v->right;
	    v->right = parent;
	    parent->left = m;
	  } else {
	    Vertex* m = v->left;
	    v->left = parent;
	    parent->right = m;
	  }
	  update(parent);
	  update(v);
	  v->parent = grandparent;
	  if (grandparent != NULL) {
	    if (grandparent->left == parent) {
	      grandparent->left = v;
	    } else {
	      grandparent->right = v;
	    }
	  }
	}
	
	void big_rotation(Vertex* v) {
	  if (v->parent->left == v && v->parent->parent->left == v->parent) {
	    // Zig-zig
	    small_rotation(v->parent);
	    small_rotation(v);
	  } else if (v->parent->right == v && v->parent->parent->right == v->parent) {
	    // Zig-zig
	    small_rotation(v->parent);
	    small_rotation(v);
	  } else {
	    // Zig-zag
	    small_rotation(v);
	    small_rotation(v);
	  }  
	}
	
	// Makes splay of the given vertex and makes
	// it the new root.
	void splay(Vertex*& root, Vertex* v) {
	  if (v == NULL) return;
	  while (v->parent != NULL) {
	    if (v->parent->parent == NULL) {
	      small_rotation(v);
	      break;
	    }
	    big_rotation(v);
	  }
	  root = v;
	}
	
	// Searches for the given key in the tree with the given root
	// and calls splay for the deepest visited node after that.
	// If found, returns a pointer to the node with the given key.
	// Otherwise, returns a pointer to the node with the smallest
	// bigger key (next value in the order).
	// If the key is bigger than all keys in the tree, 
	// returns NULL.
	Vertex* find(Vertex*& root, int key) {
	  Vertex* v = root;
	  Vertex* last = root;
	  Vertex* next = NULL;
	  while (v != NULL) {
	    if (v->key >= key && (next == NULL || v->key < next->key)) {
	      next = v;
	    }
	    last = v;
	    if (v->key == key) {
	      break;      
	    }
	    if (v->key < key) {
	      v = v->right;
	    } else {
	      v = v->left;
	    }
	  }
	  splay(root, last);
	  return next;
	}
	//this part of the code gives makes this binary search tree diferent
	//function find help us to search a node with an specific key
	//instead this function looks for the kth s node on the tree making
	//this tree implicit
    void pushdown(Vertex *x){
		if(x == NULL) return;
		if(x->reverse){
			swap(x->left,x->right);
			if(x->left != NULL)x->left->reverse = !x->left->reverse;
			if(x->right != NULL)x->right->reverse = !x->right->reverse;
			x->reverse = false;
		}
		/*	if(x->lazy){
			char y = x->data;
		//	if(y == 'z') y = 'a';
		//	else y++;
			if(x->left != NULL)x->left->lazy += x->lazy;
			if(x->right != NULL)x->right->lazy += x->lazy;
			x->lazy = 0;
		}*/
	}
     Vertex* search(Vertex* R,int kth){
        pushdown(R);
        int s = 0;
        if(R == NULL) return R;
        if(R->left != NULL) s =  R->left->size;
        if(kth == s+1) return R;
        else if(kth < s + 1) return search(R->left,kth);
        else return search(R->right,kth-s-1);
    }
	void split(Vertex* root, int key, Vertex*& left, Vertex*& right,bool flag) {
	  if(!flag) right = find(root, key);
      else right = search(root,key);
      splay(root, right);
	  if (right == NULL) {
	    left = root;
	    return;
	  }
	  left = right->left;
	  right->left = NULL;
	  if (left != NULL) {
	    left->parent = NULL;
	  }
	  update(left);
	  update(right);
	}
    Vertex* root = NULL;
    //funcion to move range [l,r] to the k th
    // on the remaining tree
    void move(int l,int r,int k){
        Vertex* left = NULL;
        Vertex* middle = NULL;
        Vertex* right = NULL;
        split(root,l,left,middle,true);
        split(middle,r-l+1,middle,right,true);
        root = merge(left,right);
        split(root,k+1,left,right,true);
        root = merge(merge(left,middle),right);
    }
    // exchange range[l,r] with range[m,n]
    void change(int l, int r, int m, int n){
        n++;r++;
        Vertex* left = NULL;
        Vertex* right = NULL;
        Vertex* second = NULL;
        Vertex* ll = NULL;
        Vertex* rr = NULL;
        Vertex* first = NULL;
        split(root,m,left,second, true);  
        split(second,n-m+1,second,right,true);
        if(second != NULL) second->reverse = !second->reverse;
        split(left,l,ll,first,true);
        split(first,r-l+1,first,rr,true);
        //if(first != NULL) first->reverse = !first->reverse;
        root = merge(ll,second);
        root = merge(root,rr);
        root = merge(root,first);
        root = merge(root,right);
    }

	Vertex* merge(Vertex* left, Vertex* right) {
	  pushdown(left); pushdown(right);
      if (left == NULL) return right;
	  if (right == NULL) return left;
	  Vertex* min_right = right;
	  while (min_right->left != NULL) 
	    min_right = min_right->left;

	  splay(right, min_right);
	  right->left = left;
	  update(right);
	  return right;
	}
    void dfs(Vertex* u){
        if(u == NULL) return;
        pushdown(u);
        dfs(u->left); cout << u->data;
        dfs(u->right);
    }
    void insert(int x,char data){
        Vertex* left = NULL;
        Vertex* right = NULL;
        Vertex* newV = NULL;
        split(root,x,left,right,false);
        if(right == NULL or right->key != x)
            newV = new Vertex(x,data);
        root = merge(merge(left,newV),right);
    }

    void trans(){dfs(root);}
    void find(int x){Vertex* p= search(root,x);splay(root,p);}
    rope(string x){
        for (int i = 0,j = x.size()-1;i<=j; ++i,--j){
            if(i == j)insert(i,x[i]);
            insert(j,x[j]);
            insert(i,x[i]);
        }
    }
};

int main(){

    string x; cin >> x;
    int n; cin >> n;

    rope R(x);
   // R.trans();
    while(n--){
        int i,j,k,l; cin >> i >> j >> k >> l;
        R.change(i,j,k,l);
        //R.trans();
    }
   R.trans();
}
