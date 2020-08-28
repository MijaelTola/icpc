#include <bits/stdc++.h>

using namespace std;

bool is[100010];
bool ver[100010];
int main() {
    
    int n,k;
    cin >> n >> k;

    for (int i = 2; i * i <= 100010; ++i) 
        for (int j = i + i; j <= n; j += i)
            is[j] = 1;

    vector<int> p;
    for (int i = 2; i <= n; ++i)
        if(!is[i]) p.push_back(i);
    
    int cnt = 0;
    for (int i = 1; i < (int)p.size(); ++i) {
        if(!is[p[i] + p[i - 1] + 1]) 
            ver[p[i] + p[i - 1] + 1] = 1;
    }

    for (int i = 2; i <= n; ++i)
        cnt += ver[i];
    if(cnt >= k) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

