#include <bits/stdc++.h>

using namespace std;

long long dis[30][30];

int main() {

    for (int i = 0; i < 30; ++i)
        for (int j = 0; j < 30; ++j)
            dis[i][j] = 1e9;

    string s,t;
    cin >> s >> t;

    int m;
    cin >> m;
    while(m--) {
        char x,y;
        long long w;
        cin >> x >> y >> w;
        dis[x - 'a'][y - 'a'] = min(dis[x - 'a'][y - 'a'], w);
    }

    for (int i = 0; i < 30; ++i)
        dis[i][i] = 0;

    if(s.size() != t.size()) return cout << "-1\n", 0;

    for (int k = 0; k < 30; ++k)
        for (int i = 0; i < 30; ++i)
            for (int j = 0; j < 30; ++j)
                if(dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];

    
    long long sum = 0;
    string ans = "";
    for (int i = 0; i < (int)s.size(); ++i) {
        int a = s[i] - 'a';
        int b = t[i] - 'a';
        int cost = 1e9;
        int id = -1;
        for (int i = 0; i < 26; ++i) {
            long long cur = dis[a][i] + dis[b][i];
            if(dis[a][i] >= 1e9 or dis[b][i] >= 1e9) continue;
            if(cur < cost) {
                cost = cur;
                id = i;
            }
        }

        if(id == -1) return cout << "-1\n", 0;

        sum += cost;
        ans += (char)(id + 'a');
    }
    cout << sum << "\n";
    cout << ans << "\n";
                        
    return 0;
}

