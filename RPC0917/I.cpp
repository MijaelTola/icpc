#include <bits/stdc++.h>

using namespace std;

int main(){
    int k;
    long long n;
    while(cin >> n >> k){
        long long ans = LLONG_MAX;
        
        for (int i = 0; i <= 50 and i + k <= 50; ++i){
            long long cur = n;
            for (int j = i; j < i + k; ++j)
                cur |= (1LL << j);
            if(cur >= n) ans = min(ans,cur);
            cur = n;
            for (int j = i; j < i + k; ++j)
                cur |= (1LL << j);
            for (int j = 0; j < i; ++j)
                cur &= ~(1LL << j);
            cout<< cur << ": " << bitset<10> (cur) << "\n";
            if(cur >= n) ans = min(ans,cur);
            cur = 0;
            for (int j = i; j < i + k; ++j)
                cur |= (1LL << j);

            if(cur >= n) ans = min(ans,cur);
        }

        cout << ans << "\n";
    }
    
    return 0;
}

