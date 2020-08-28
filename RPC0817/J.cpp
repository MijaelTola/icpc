#include <bits/stdc++.h>

using namespace std;

int di(int x,int y, int a,int b){
    return abs(x - a) + abs(y - b);
}

vector< pair<int,int> > v, b;
vector<int> G[210];
bool vis[210];
int match[210],n;

int aug(int l){
    if(vis[l]) return 0;
    vis[l] = 1;
    for (int j = 0; j < (int)G[l].size(); ++j){
        int r = G[l][j];
        if(match[r] == -1 or aug(match[r])){
            match[r] = l; return 1;
        }
    }
    return 0;
}

bool ver(int k){
    for (int i = 0; i < 210; ++i)
        G[i].clear();
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            int d = di(v[i].first, v[i].second,b[j].first,b[j].second);
            if(d <= k)G[i].push_back(j + n);
        }
    }
    
    memset(match,-1,sizeof match);
    int mcbm = 0;
    for (int l = 0; l < n; ++l){
        memset(vis,false,sizeof vis);
        mcbm += aug(l);
    }
    return mcbm == n;
}
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i){
        int x,y; cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    
    for (int i = 0; i < n; ++i){
        int x,y; cin >> x >> y;
        b.push_back(make_pair(x,y));
    }

    if(ver(0)) return cout << "0\n",0;
    int a = -1,b = 1e9;
    while(b - a > 1){
        int mid = (a + b) >> 1;
        if(ver(mid)) b = mid;
        else a = mid;
    }
    
    cout << b << "\n";
    return 0;
}
