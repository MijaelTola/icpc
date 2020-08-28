#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        vector<int> even;
        vector<int> odd;
        int n,k; cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if(i & 1) odd.push_back(x);
            else even.push_back(x);
        }
        sort(even.rbegin(),even.rend());
        sort(odd.begin(),odd.end());
        int pos = 0;
        while(pos < k and pos < (int)even.size() 
                and pos < (int)odd.size()) {
            int x = even[pos];
            int y = odd[pos];
            if(x <= y) break;
            even[pos] = y;
            odd[pos] = x;
            pos++;
        }
        
        long long s1 = 0;
        for (int i = 0; i < (int)even.size(); ++i) 
            s1 += even[i]; 

        long long s2 = 0;
        for (int i = 0; i < (int)odd.size(); ++i) 
            s2 += odd[i]; 

        if(s2 > s1) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}





