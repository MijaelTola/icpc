#include <bits/stdc++.h>

using namespace std;

int v[500010];

int main() {
    string s;
    cin >> s;
    
    for (int i = 0; i < (int)s.size(); ++i) {
        if(s[i] == '<') v[i + 1] = v[i] + 1;
        if(s[i] == '>') v[i + 1] = v[i] - 1;
    }
    
    int mn = 1e9;
    for (int i = 0; i <= (int)s.size(); ++i) 
        mn = min(v[i], mn);
    
    cout << mn << " gg\n";
    if(mn < 0) 
        for (int i = 0; i <= (int)s.size(); ++i)
            v[i] += abs(mn);
    
    
    long long ans = 0;

    for (int i = 0; i <= (int)s.size(); ++i)
        ans += v[i];
    cout << ans << "\n";
    return 0;
}
 
