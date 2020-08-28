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
    int cnt;
    int start;
    bool a,b,end;
    node* t[4];
    node(int c){cnt = c;a = false,b = false; end = false;}
    node(){}
};

//
struct Trie{
    node* root;
    int sz;
    Trie(){root = new node(0);}
    
    int getPos(char x){
        if(x == 'A') return 0;
        if(x == 'C') return 1;
        if(x == 'G') return 2;
        if(x == 'T') return 3;
        return 0;
    }
    void insertA(int x,string &pattern){
        node* copy = root;
        for (int i = x; i < (int)pattern.size(); ++i){
            int v = getPos(pattern[i]);
            if(copy->t[v] == NULL)
                copy->t[v] = new node(0);
            copy->t[v]->start = x;
            copy->t[v]->a =true;
            copy->t[v]->cnt++;
            copy = copy->t[v];
        }
    }

    void insertB(int x,string &pattern){
        node* copy = root;
        for (int i = x; i < (int)pattern.size(); ++i){
            int v = getPos(pattern[i]);
            if(copy->t[v] == NULL)
                copy->t[v] = new node(0);
            copy->t[v]->start = x;
            copy->t[v]->cnt++;
            copy->t[v]->b = true;
            copy = copy->t[v];
        }
    }

    pair<int,int> find(){
        queue<pair<node*,int> > q;
        node* copy = root;
        q.push({copy,0});
        int ans = 1e8;
        int pos = 0;
        while(!q.empty()){
            node* c = q.front().first;
            int a = q.front().second;
            q.pop();
            if(c->a and !c->b and a < ans){
                ans = a;
                pos = c->start;
                continue;
            }
            if(c == NULL) continue;
            for (int i = 0; i < 4; ++i){
                node* p = c->t[i];
                if(p == NULL) continue;
                //if(p->a and !p->b)cout << v.first << " " << a+1 << " " << v.second->start << endl; 
                q.push({p,a+1});
            }
        }
        return {pos,ans};
    }
};
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    Trie T;  
    string a,b;
    cin >> a >> b;
    for (int i = 0; i < (int)a.size(); ++i)
        T.insertA(i,a);
    for (int i = 0; i < (int)b.size(); ++i)
        T.insertB(i,b);
    pair<int,int> p = T.find();
    for (int i = p.first; i < p.first+p.second; ++i)
        cout << a[i];
    return 0;
}

