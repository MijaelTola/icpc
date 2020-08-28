#include <bits/stdc++.h>

using namespace std;

int main(){
    string x; cin >> x;
    
    int ans = 1e9;
    for (int i = 0; i < (int)x.size(); ++i){
        for (int j = i; j < (int)x.size(); ++j){
            int cur = 0;
            for (int k = 0; k < (int)x.size(); ++k){
                bool match = true;
                int p = k;
                for (int l = i; l <= j; ++l)
                    if(x[l] != x[p++]) match = false;
                cur += match;
                if(match) k += (j - i);
            }
            int sz = j - i + 1;
            int mn = x.size() - sz*cur + sz + cur;
            ans = min(ans,mn);
        }
    }
    cout <<min(ans,(int)x.size()) << "\n";
    return 0;
}

