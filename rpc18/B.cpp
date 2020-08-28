#include <bits/stdc++.h>

using namespace std;


vector<pair<pair<double,double>, int > >  v;
string ss[510];
int main(){
    
    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        double x,y;
        cin >> s >> x >> y;
        v.push_back({{y,x},i});
        ss[i] = s;
    }

    sort(v.begin(),v.end());
    
    double ans = INT_MAX;
    int id = -1;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        double sum = 0;
        int pos = 0;
        while(cur < 3 and pos < n) {
            if(pos == i){ 
                pos++;
                continue;
            }
            sum += v[pos].first.first;
            cur++;
            pos++;
        }
        sum += v[i].first.second;
        if(sum < ans) {
           ans = sum;
           id = i;
        }
    }
    
    cout.precision(9);
    cout << fixed << ans << "\n";
    int cur = 0;
    int pos = 0;
    int ts = 0;
    cout << ss[v[id].second] << "\n";
    while(cur < 3 and pos < n) {
        if(pos == id) {pos++;continue;}
        cout << ss[v[pos].second] << "\n";
        pos++;
        cur++;
    }
    return 0;
}

