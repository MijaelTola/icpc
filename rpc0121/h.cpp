#include <bits/stdc++.h>

using namespace std;

struct node{
    map<char,node*> t;
    bool end;
    set<string> st;

    node(){end = false; }
};

struct trie{
    node* root;
    trie(){root = new node();}


    void insert(node *copy, int pos, const string p, string cur) {
        if(pos == (int)p.size()) {
            copy->end = true;
            copy->st.insert(cur);
            return;
        }

        char v = p[pos];
        if(copy->t[v] == NULL)
            copy->t[v] = new node();
        insert(copy->t[v], pos + 1, p, cur);
        
        for (auto x: copy->t[v]->st) {
            copy->st.insert(x);
        }
    }

    string find(string pattern) {
        node *copy = root;

        for (char v: pattern) {
            if(copy->t[v] == NULL) return "";
            copy = copy->t[v];
        }

        if(copy->st.size() == 1) return *copy->st.begin();
        if(copy->end) return *copy->st.begin();
        return "";
    }

    void insert(string s, string cur) {
        insert(root, 0, s, cur);
    }

};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {

        trie tr;
        int p,r;
        cin >> p >> r;
        
        for (int i = 0; i < p; ++i) {
            int c;
            cin >> c;
            string ini = "";
            for (int j = 0;j < c; ++j) {
                string s;
                cin >> s;
                if((int)ini.size() == 0) ini = s;
                tr.insert(s, ini);
            }
        }
    
        for (int i = 0; i < r; ++i) {
            int c;
            cin >> c;

            set<string> ans;

            for (int j = 0; j < c; ++j) {
                string s;
                cin >> s;
                string cur = tr.find(s);
                //cout << cur << "\n";
                if(cur.size() > 0) ans.insert(cur);
            }
            cout << ans.size() << "\n";
        }

    }
    return 0;
}
