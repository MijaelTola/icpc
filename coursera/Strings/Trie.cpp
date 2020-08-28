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
    bool end;
    node(){end = false;}
};

struct trie{
    node* root;
    trie(){root = new node();}
    void insert(string pattern){
        node* copy = root;
        for (char v: pattern){
            if(copy->t[v] == NULL)
                copy->t[v] = new node();
            copy = copy->t[v];
        }
        copy->end = true;
    }

    bool find(string pattern){
        node* copy = root;
        string path = "";
        for(char v: pattern){
            if(copy->end) break;
            if(copy->t[v] == NULL) return false;
            path += v;
            copy = copy->t[v];
        }
        return copy->end;
    }
    
    void TrieMatching(string Text){
        int pos = 0;
        while(!Text.empty()){
            if(find(Text)) cout << pos << " ";
            Text.erase(Text.begin()+0);
            pos++;
        }
    }
};
int main(){

    string text; cin >> text;
    int n; cin >> n;
    trie T;
    for (int i = 0; i < n; ++i){
        string x; cin >> x;
        T.insert(x);
    }
    T.TrieMatching(text);
    return 0;
}

