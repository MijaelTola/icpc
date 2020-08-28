#include <bits/stdc++.h>

using namespace std;

struct node{
    map<int, node*> nxt;
    bool end;
    int ctr;
    int val;
    node(){
        end = false;
        ctr = 0;
    }

};

struct trie{
    node* root;
    trie(){root = new node();}


    void insert(int x) {
        node *cur = root;
        for (int i = 30; i >= 0; i--) {
            int ch = (x >> i) & 1;
            if (cur->nxt[ch] == 0) {
                cur->nxt[ch] = new node();
            }
            cur->nxt[ch]->ctr++;
            cur = cur->nxt[ch];
        }
        cur->val = x;
    }

    void pop(int x) {
        node *cur = root;
        for (int i = 30; i >= 0; i--)
        {
            int ch = (x >> i) & 1;
            cur->nxt[ch]->ctr--;
            if (cur->nxt[ch]->ctr == 0) {
                cur->nxt[ch] = NULL;
                break;
            }
            cur = cur->nxt[ch];
        }
    }

    int find(int x) {
        node *cur = root;
        for (int i = 30; i >= 0; i--) {
            int ch = (x >> i) & 1;
            for (int j = 1; j >= 0; j--){
                if (cur->nxt[j ^ ch] != NULL) {
                    cur = cur->nxt[j ^ ch];
                    break;
                }
            }
        }
        return cur->val;
    }

};

int main() {


    trie T;
    T.insert(0);
    int q;
    cin >> q;

    while(q--) {
        char c;
        int x;
        cin >> c >> x;
        if(c == '+') 
            T.insert(x);
        if(c == '-')
            T.pop(x);
        if(c == '?')
            cout << (x ^ T.find(x)) << "\n";
    }


    return 0;
}

