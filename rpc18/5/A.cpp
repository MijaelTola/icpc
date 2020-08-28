#include <bits/stdc++.h>

using namespace std;

bool sfinal[20];
vector<int> G[20][26];
string s;
bool f(int pos, int tr) {
    if(pos == (int)s.size()) return sfinal[tr];
    bool ans = 0;
    for (int i = 0; i < (int)G[tr][s[pos] - 'a'].size(); ++i) {
        ans |= f(pos + 1, G[tr][s[pos] - 'a'][i]);
    }
    return ans;
}
int main(){
    int t; cin >> t;
    while(t--) {
        memset(sfinal,false,sizeof sfinal);
        int n,m,s,k;
        cin >> n >> m >> s >> k;
        for (int i = 0; i < s; ++i) {
            char a; cin >> a;
        }

        for (int i = 0; i < k; ++i) {
            int x; cin >> x;
            sfinal[x] = 1;
        }
        for (int i = 0; i < m; ++i) {
            int x,y;
            char z;
            cin >> x >> y >> z;
            G[x][z - 'a'].push_back(y);
        }

        int q; cin >> q;
        while(q--) {
            cin >> s;
            if(f(0,0)) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}

