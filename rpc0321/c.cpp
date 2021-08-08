#include <bits/stdc++.h>

using namespace std;

int v[100010];
int ans[100010];

int main() {
    int n,p;

    cin >> n >> p;

    
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
 
    int solved = 0;
    for (int i = n; i >= 1; i--) {
        if(v[i] > v[i + 1]) {
            solved++;
            ans[i] = solved;
        }
        ans[i] = solved;
    }
    
    
    if(solved > 0 and solved != p) return cout << "ambiguous\n", 0;

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << "\n";
   
    return 0;
}

