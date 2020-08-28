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
    bool a;
    int b;
    map<char,node*> t;
    node(){a=false;b = 0;}
};

struct Trie{
    node* root;
    Trie(){root = new node();}
    
    void insert(string &pattern,bool flag){
        node* copy = root;
        for (int i = 0; i < (int)pattern.size(); ++i){
            char v = pattern[i];
            if(copy->t[v] == NULL) copy->t[v] = new node();
            if(flag) copy->t[v]->a = true;
            else copy->t[v]->b++;
            copy = copy->t[v];
        }
    }

    ll dfs(node* u){
        if(!u->a or !u->b) return 0LL;
        ll ans = 0LL;
        for (pair<char,node*> v: u->t)
            if(v.second->a and v.second->b)ans += dfs(v.second) + v.second->b;
        return ans;
    }
    
    ll find(){
        node* copy = root;
        ll ans = 0LL;
        for (pair<char,node*> v: copy->t)
            if(v.second->a and v.second->b) ans += dfs(v.second)+v.second->b;
        return ans;
    }
};
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n and n != -1){
        Trie T;
        
        for (int i = 0; i < n; ++i){
            string x; cin >> x;
            T.insert(x,true);
        }
        for (int i = 0; i < n; ++i){
            string x; cin >> x;
            T.insert(x,false);
        }
        cout << T.find() << "\n";
    }
    return 0;
}

