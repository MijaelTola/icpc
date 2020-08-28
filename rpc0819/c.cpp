#include <bits/stdc++.h>

using namespace std;

int n;
int v[366];
int main() {
    
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
    int last = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j >= last; --j) {
            int dif = max(v[i] - v[j],0);
            sum += dif;
        }
        if(sum >= 20) {
            ans++;
            last = i;
        }
    }
    cout << ans + 1 << "\n";
    

}

