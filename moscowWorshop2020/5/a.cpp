#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    long long sum;
    node *next, *top;
    node() {
        next = NULL;
        sum = 0;
    }
    node (int _) {
        val = _;
    }
    node* push(node *s, int x) {
        node *cur = new node(x);
        cur->next = s;
        cur->sum = s->sum + x;
        s = cur;
        return cur; 
    }

    pair<node*, int> pop(node *s) {
        node *cur = s;
        int val = cur->val;
        cur = cur->next;
        return {cur, val};
    }
};

vector<node*> version;

int main() {

    node *stack = new node();

    version.push_back(stack);

    int n;
    cin >> n;

    while(n--) {
        int t,x;
        cin >> t >> x;
        if(x) {
            version.push_back(version[t]->push(version[t], x));
        } else {
            version.push_back(version[t]->pop(version[t]).first);
        }
    }
    
    long long ans = 0;

    for (int i = 0; i < (int)version.size(); ++i) {
        node * cur = version[i];
        ans += cur->sum;
    }

    cout << ans << "\n";
    return 0;
}
