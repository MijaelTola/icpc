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

using namespace std;

typedef long long ll;

deque<string > list[100100];

int h(string s,ll p, int x,ll m){
    ll hash = 0;
    for (int i = (int)s.size()-1; i >= 0; --i)
        hash = ((((hash*x+s[i])%p)+p)%p);
    return hash%m;
}
void add(string x, int l){
    for (int i = 0; i < (int)list[l].size(); ++i)
        if(list[l][i] == x) return;
    list[l].push_front(x);
}

void del(string x,int l){
    int id = -1;
    for (int i = 0; i < (int)list[l].size(); ++i){
        if(list[l][i] == x){
            id = i;
            break;
        }
    }
    if(id == -1) return;
    list[l].erase(list[l].begin()+id);
}
bool find(string x, int l){
    for (int i = 0; i < (int)list[l].size(); ++i)
        if(list[l][i] == x) return true;
    return false;
}

void check(int l){
    for (int i = 0; i < (int)list[l].size(); ++i)
        cout << list[l][i] << " ";
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    ll p = 1000000007;
    int x = 263;
    int m,q;
    cin >> m >> q;
    while(q--){
        string c,word;
        int n;
        cin >> c;
        if(c == "add"){
            cin >> word;
            int l = h(word,p,x,m);
            add(word,l);
        }
        if(c == "del"){
            cin >> word;
            int l = h(word,p,x,m);
            del(word,l);
        }
        if(c == "check"){
            cin >> n;
            check(n);
        }
        if(c == "find"){
            cin >> word;
            int l = h(word,p,x,m);
            if(find(word,l)) cout << "yes\n";
            else cout << "no\n";
        }
    }
    return 0;
}

