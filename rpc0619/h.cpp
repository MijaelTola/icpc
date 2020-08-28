#include <bits/stdc++.h>

using namespace std;

int v[100000010];
bool vis[100000010];
int b[1000010];
int n,q;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        b[i] = x;
        v[x] = 1;
        vis[x] = 1;
    }
    
    for (int i = 1; i < 100000010; ++i) 
        v[i] += v[i - 1];
    
    sort(b, b + n);
    while(q--) {
        int x; 
        cin >> x;
        long long ans = 0;
        long long cnt = 0;
        for (int i = 0; i < n; ++i) {
            int left = x - b[i];
            if(left < 0) continue;
            if(left >= b[i]) {
                cnt++;
                continue;
            }
            int cur = v[left];
            if(vis[left] and left == b[i]) cur--;
            ans += cur;
        }
        cout << ans + (cnt * (cnt - 1) / 2) << "\n";
    }
    

    return 0;
}
