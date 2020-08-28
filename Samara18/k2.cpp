#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > v;
int main() {
    
    int n,m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        v.push_back({x,i});
    }
    
    sort(v.begin(), v.end());
    int ans = 0;
    int cur = 0;
    int id = 0;
    int pos = 0;
    while(m and pos < n) {
        if(v[pos].second >= id) {
           if(v[pos].first > cur) ans++;
           id = max(id, v[pos].second);
           cur++;
           m--;
        }
        pos++;
    }
    cout << ans << "\n";
    return 0;
}

