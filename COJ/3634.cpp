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

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    ll t;
    char r;
    while(cin >> n >> t >> r){
        string s; cin >> s;
        string l;
        cin.ignore();
        getline(cin,l);
        cin >> s;
        int moves = (t%n)*2;
        int dif  = n*2-moves;
        if(r == 'R'){
           // cout << dif << "\n";
            cout << s << "\n";
            for (int i = dif; i < (int)l.size(); ++i) cout << l[i];
            for (int i = 1; i <= dif; ++i) cout << l[i];
            cout << "\n";
            cout << s << "\n";
        }else{
            cout << s << "\n";
            dif = (int)l.size() - dif;
            for (int i = dif-1; i < (int)l.size(); ++i) cout << l[i];
            for (int i = 1; i < dif; ++i) cout << l[i];
            cout << "\n";
            cout << s << "\n";
        }
    }
    return 0;
}

