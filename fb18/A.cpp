#include <bits/stdc++.h>

using namespace std;

string id[55];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    int c = 1;
    while(t--) {
        int n,k;
        long long v;
        cin >> n >> k >> v;
        for (int i = 0; i < n; ++i) 
            cin >> id[i];
        
        int pos = (k * (v - 1)) % n;
        
        vector<pair<int,string> > ans;
        for (int i = pos; i < pos + k; ++i)
            ans.push_back({i % n,id[i % n]});

        sort(ans.begin(),ans.end());
        cout << "Case #" << c++ << ": ";
        for (int i = 0; i < (int)ans.size(); ++i)
            cout << ans[i].second << " ";
        cout << "\n";
    }

    return 0;
}

