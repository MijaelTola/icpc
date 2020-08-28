#include <bits/stdc++.h>
 
using namespace std;
 
int a[27];
vector<int> v[27];
int ans[100010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);   
    int t;
    cin >> t;
    while(t--) {
        for (int i = 0; i < 27; ++i) v[i].clear();
        memset(a,0,sizeof a);
        string s; cin >> s;
        for (int i = 0; i < (int)s.size(); ++i) {
            a[s[i] - 'a']++;
            v[s[i] - 'a'].push_back(i);
        }
 
        bool found = 0;
        bool done = 0;
        for (int i = 0; i < 26; ++i) {
            if(a[i] % 2 == 0) continue;
            else if((int)s.size() % 2 != 0 and found == 0){
                found = 1; continue;
            }
            done = 1;
            break;
        }
 
        if(done) {
            int cur = 0;
            for (int i = 0; i < 27; ++i) if(a[i]) cur++;
            if(cur == 1) for (int i = 0; i < (int)s.size(); ++i)
                cout << i + 1 << " ";
            else cout << "-1";
            cout << "\n";
            continue;
        }
 
        int pl = 0;
        int pr = s.size() - 1;
        int pos = 0;
        int sum = 0;
        while(pl < pr and pos < 27) {
            int ps = 0;
            while(a[pos] > 1 and a[pos] > 1 and pl < pr) {
                ans[pl] = v[pos][ps];
                ans[pr] = v[pos][ps + 1];
                sum += v[pos][ps] + 1;
                sum += v[pos][ps + 1] + 1;
                a[pos] -= 2;
                pl++;pr--;
                ps += 2;
            }
            pos++;
        }
        int n = s.size();
        n = n * (n + 1) / 2;
        int x = n - sum - 1;
        if(s.size() % 2 != 0)  
                ans[ s.size() / 2] = x;
        for (int i = 0; i < (int)s.size(); ++i)
            cout << ans[i] + 1 << " ";
        cout << "\n";
    }
    return 0;
}

