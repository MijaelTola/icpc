#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;
    int k = 1;
    while(t--) {
        long long u;
        cin >> u;

        vector<int> a(26,11), no(26, 0);
        

        vector<pair<int, string> > v;
        for (int i = 0; i < 10000; ++i) {
            int dm;
            string r,m;
            cin >> dm >> r;
            v.emplace_back(dm, r);
            m = to_string(dm);

            for (int i = m.size() - 1; i >= 0; i--) {
                int c = r[i] - 'A';
                int e = m[i] - '0';
                a[c] = min({a[c], e});
                if(i == 0) no[c] = 1;
            }
        }

        string p = "";

        for (int i = 0; i < 26; ++i)
            if(a[i] != 11) 
                p += (char)(i + 'A');

        string ans = "";

        do {
            map<char, int> mp;
            for (int i = 0; i < (int)p.size(); ++i) { 
                if(no[p[i] - 'A'] or i > a[p[i] - 'A']) continue;
                mp[p[i]] = i;
            }
            
            bool flag = 1;
            for (auto p: v) {
                long long cur = 0;
                for (auto c: p.second) {
                    cur = 10 * cur + mp[c];
                }
                flag &= cur <= p.first and (int)log10(cur) + 1 == (int)p.second.size();
            }
            
            if(flag) {
                ans = p;
                break;
            }
        }while(next_permutation(p.begin(), p.end()));
        reverse(ans.begin(), ans.end());
        cout << "Case #" << k ++ << ": " << ans << "\n";;



    }
    return 0;
}

