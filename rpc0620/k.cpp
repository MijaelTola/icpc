#include <bits/stdc++.h>

using namespace std;

int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,-1,-1,-1,0,1,1,1};
vector<char> v[3];

int main() {

    int cur = 0;

    int cnt = 0;
    for (int i = 'a'; i <= 'z'; ++i) {
        if(cnt % 9 == 0 and cnt != 0) cur++;
        v[cur].push_back(i);
        cnt++;
    }

    while(v[2].size() < 9) v[2].push_back('.');

    int n;
    cin >> n;

    while(n--) {
        string s,t;
        cin >> s >> t;

        if(s.size() != t.size()) {
            cout << "3\n";
            continue;
        }

        
        if(s == t) {
            cout << "1\n";
            continue;
        }
    
        bool flag = 1;
        for (int i = 0; i < (int)s.size(); ++i) {
            
            int xa = (s[i] - 'a') / 9;
            int ya = (s[i] - 'a') % 9;

            bool f = s[i] == t[i];
            for (int j = 0; j < 8; ++j) {
                int u = xa + dx[j];
                int vv = ya + dy[j];
                if(u >= 0 and u < 3 and vv >= 0 and vv < 9) {
                    f |= v[u][vv] == t[i];
                }
            }
            flag &= f;
        }

        if(flag) cout << "2\n";
        else cout << "3\n";
    }


    return 0;
}

