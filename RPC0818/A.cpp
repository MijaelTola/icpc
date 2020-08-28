#include <bits/stdc++.h>

using namespace std;

int a[2010];
int b[2010];

map<int,int> mp;
int main(){
    
    int n,m; cin >> n >> m;

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    

    for (int i = 0; i  < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(a[i] > b[j]) continue;
            mp[b[j] - a[i]]++;
        }
    }
    
    int ans = 0;
    int id = 0;
    for (pair<int,int> p: mp) {
        if(p.second > ans) {
            ans = p.second;
            id = p.first;
        }
    }
    cout << id << "\n";
    return 0;
}

