#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string c;
    while(1) {
        map<string, long long> mp;
        bool in = 0;
        while(cin >> c and c != "END") {
            in = 1;
            if(c[0] == 'R') {
                 string x;
                 int y;
                 cin >> x >> y;
                 mp[x] += y;
                 continue;
            }
            if(c[0] == 'G') {
                string x;
                int y;
                cin >> x >> y;
                mp[x] -= y;
                continue;
            }
            if(c[0] == 'P') {
                string x,z;
                int y;
                cin >> x >> y >> z;
                mp[x] -= y;
                mp[z] += y;
            }
        }
        if(in == 0) break;
        vector<pair<string, long long> > ans;
        for (auto p: mp)
            ans.push_back(p);
        
        cout << "{";
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i].first << "=" << ans[i].second;
            if(i + 1 < ans.size())
                cout << ", ";
        }
        cout << "}\n";

    }

    return 0;
}

