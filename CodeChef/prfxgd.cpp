#include <bits/stdc++.h>

using namespace std;

int t,k,x;

string s;

int main() {
    
    cin >> t;
    
    while(t--) {
        vector<int> a(27,0);

        cin >> s >> k >> x;
        
        string ans = "";
        for (int i = 0; i < (int)s.size(); ++i) {
            a[s[i] - 'a']++;
            if(a[s[i] - 'a'] > x) {
                if(k) a[s[i] - 'a']--, k--; 
                else break;
            } else ans += s[i];
        }
        cout << ans.size() << "\n";
    }
    return 0;
}

