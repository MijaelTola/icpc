#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int t;
    cin >> t;
    while(t--){
        vector<pair<int,int> > v;
        int n; cin >> n;
        for (int i = 0; i < n; ++i){
            int x,y;
            cin >> x >> y;
            v.push_back(make_pair(y,x));
        }

        sort(v.begin(),v.end());

        for (int i = 0; i < n; ++i)
            cout << v[i].second << " ";
        cout << "\n";
    }
    return 0;
}

