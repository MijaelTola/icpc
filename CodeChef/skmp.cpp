#include <bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;
    
    while(t--) {
        string a,b;
        cin >> a >> b;
     
        vector<int> c(27, 0), vis(27,0);
        for (int i = 0; i < (int)a.size(); ++i) {
            c[a[i] - 'a']++;
        }
        
        string cur = "";
        for (int i = 0; i < (int)b.size(); ++i) {
            c[b[i] - 'a']--;
            if(!vis[b[i] - 'a']) {
                cur += b[i];
                vis[b[i] - 'a'] = 1;
            }
        }
        
        string ans = "";
        bool flag = 1;
       
        for (char i = 'a'; i <= 'z'; ++i) {
            if(i == b[0]) {
                if(cur.size() == 1 or cur[1] < i) {
                    ans += b;
                    flag = 0;
                }
            }
            while(c[i - 'a']--) ans += i;
            
            if(i == b[0] and flag)
                ans += b;
        }

        cout << ans<< "\n";
    }
    return 0;
}

