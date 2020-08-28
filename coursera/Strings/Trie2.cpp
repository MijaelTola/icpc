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

struct node{
    map<char,node*> t;
    int key;
    bool end;
    node(int k){key = k;end = false;}
};

struct trie{
    node* root;
    int sz;
    trie(){sz = 0; root = new node(sz);}

    void insert(string pattern){
        node* copy = root;
        for (char v: pattern){
            if(copy->t[v] == NULL)
                copy->t[v] = new node(++sz);
            copy = copy->t[v];
        }
    }
    void dfs(node* v){
        if(v == NULL) return;
        for (int i = 0; i< 26; ++i){
            if(v->t[i+'A'] != NULL){
                cout << v->key<< "->" << v->t[i+'A']->key << ":" << char(i+'A') << endl;
                dfs(v->t[i+'A']);
            }
        }
    }
    void print(){dfs(root);}
};
int main(){
    int n; cin >> n;
    trie T;
    for (int i = 0; i < n; ++i){
        string x; cin >> x;
        T.insert(x);
    }
    T.print();
    return 0;
}

