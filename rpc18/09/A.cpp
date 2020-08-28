#include <bits/stdc++.h>

using namespace std;

map<string,vector<int> > mp;
vector< pair<int,string> > v;
vector<string> b;
int n,k,m;
string s; 

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int x;
        string y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < k; ++i) 
        mp[v[i].second].push_back(v[i].first);
    
    cin >> m;

    for (int i = 0; i < m; ++i) {
        string s; cin >> s;
        b.push_back(s);
    }
    int left = 0;
    bool flag = 1;
    vector<int> go;

    for (int i = 0; i < m; ++i) {
        int p = 0;
        while(mp[b[i]][p] < left and p < (int)mp[b[i]].size()) p++;
        if((int)mp[b[i]].size() <= p) {
            flag = 0;
            break;
        }
        left = mp[b[i]][p];
        go.push_back(left);
    }

    if(!flag) return cout << "impossible\n",0;
    int right = m;
    vector<int> goback;

    for (int i = m - 1; i >= 0; i--) {
        int p = mp[b[i]].size() - 1;
        while(mp[b[i]][p] > right and p >= 0) p--;
        if(p < 0) continue;
        right = mp[b[i]][p];
        goback.push_back(right);
    }
    reverse(goback.begin(),goback.end());

    for (int i = 0; i < (int)go.size(); ++i)  
        if(go[i] != goback[i]) return cout << "ambiguous\n",0;
    cout << "unique\n";
    return 0;
}

