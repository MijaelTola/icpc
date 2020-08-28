#include <bits/stdc++.h>

using namespace std;

int s,t,v[3]; 



int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s >> v[0] >> v[1] >> v[2];

        auto get = [] (int ini) {
            int p = ini;
            int s1 = 0;
            while(p < 3) {
                if(s1 + v[p] > s) break;
                s1 += v[p++];
            }
            return p;
        };
        int ini = 0;
        int ans = 0;
        while(ini < 3) {
            int p1 = get(ini);
            reverse(v + ini, v + 3);
            int p2 = get(ini);
            reverse(v + ini, v + 3);
            if(p1 > p2) ini = p1;
            else {
                ini = p2;
                reverse(v + ini, v + 3);
            }
            ans++;
        }   
        cout << ans << "\n";
    }
    return 0;
}

