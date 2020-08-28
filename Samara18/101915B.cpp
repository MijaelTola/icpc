#include <bits/stdc++.h>

using namespace std;


double dis(double x, double y, double a, double b) {
    return sqrt((x - a) * (x - a) + (y - b) * (y - b));
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while(t--) {
        vector<pair<pair<int,int>,pair<int,int> > > v;
        int n,m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            int x,y,r,s;
            cin >> x >> y >> r >> s;
            v.push_back({{x,y},{r,s}});
        }
        int ans = 0;
        for (int i = 0; i <= 1000; i++) {
            for (int j = 0; j <= 1000; ++j) {
                priority_queue<int> q;
                int dm = m;
                for (int k = 0; k < (int)v.size(); ++k) {
                    int x = v[k].first.first;
                    int y = v[k].first.second;
                    int r = v[k].second.first;
                    int s = v[k].second.second;
                    double d = dis(i,j,x,y);
                    if(d <= r) q.push(s);
                }
                int sum = 0;
                while(!q.empty() and dm) {
                    sum += q.top();
                    q.pop();
                    dm--;
                }
                ans = max(ans, sum);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

