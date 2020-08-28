#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > v;
int main(){
    int c;
    cin >> c;
    while(c--){
        v.clear();
        int n; 
        cin >> n;
        for (int i = 0; i < n; ++i){
            int x,y; cin >> x >> y;
            v.push_back(make_pair(x,y));
        }
        int x,y,r; cin >> x >> y >> r;
        int ans = 0;
        for (int i = 0; i < (int)v.size(); ++i){
            int dx = v[i].first;
            int dy = v[i].second;
            double dis = sqrt((x - dx)*(x-dx) + (y-dy)*(y-dy));
            if(dis <= r) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}

