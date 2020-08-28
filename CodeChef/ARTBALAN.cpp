#include <bits/stdc++.h>

using namespace std;

int a[27];
int b[27];
vector<pair<int,int> > v;
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        memset(a, 0, sizeof a);
        v.clear();
        cin >> s;
        for (int i = 0; i < (int)s.size(); ++i)
            a[s[i] - 'A']++;
        
        
        for (int i = 0; i < 26; ++i)
            v.push_back({a[i],i});

        s = "";

        sort(v.rbegin(), v.rend()); 
        for (int i = 0; i <  (int)v.size(); ++i) {
            for (int j = 0; j < (int)v[i].first; j++) 
                s += (char)(v[i].second + 'A');
        }
        int sz = s.size();
        int ans = 1e9;
        for (int i = 1; i < 27; ++i) {
            if(sz % i != 0) continue;
            string t = "";
            int dv = sz / i;
            for (int j = 0; j < (int)v.size() and j < i; ++j) {
                int dt = dv;
                while(dt--) 
                    t += (char)(v[j].second + 'A');
                
            }

            memset(b, 0, sizeof b);
            int sum = 0;
            for (int j = 0; j < (int)t.size(); j++) 
                b[t[j] - 'A']++;
            for (int j = 0; j < 26; ++j) 
                if(a[j] > b[j])sum += abs(b[j] - a[j]);
            ans = min(ans, sum);
        }
        cout << ans << "\n";
    }
    return 0;
}

