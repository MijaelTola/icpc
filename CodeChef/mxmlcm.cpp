#include <bits/stdc++.h>

using namespace std;


int main() {
   
    int t;
    cin >> t;
    
    auto lcm = [] (long long a, long long b) -> long long{
        return a * b / __gcd(a, b);  
    };

    while(t--) {
        int n,m;
        cin >> n >> m;
        vector<int> v(n);
        
        for (int &x: v) cin >> x;
        

        long long cur = v[0];
        for (int x: v) 
            cur = lcm(cur, x);
        
        long long ans = 0;
        int id = 1;

        for (int i = 1; i <= m; ++i) {
            long long l = lcm(cur, i);
            if(l > ans) {
                ans = l;
                id = i;
            }
        }

        cout << id << "\n";

        
    }
    return 0;
}

