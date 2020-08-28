#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    int k = 0;
    while(t--){ k++;
        string x; cin >> x;

        int ans = 0;
        int ans2 = 0;
        bool flag = false;
        for (int i = 0; i < (int)x.size();++i){
            ans += x[i]-'0';
            ans2 = 0;
            for (int j = i+1; j < (int)x.size(); ++j){
                ans2 += x[j]-'0';
                if(j+1 < (int)x.size()) ans2 *=10;
            }
            
            if(__gcd(ans,ans2)==1){
                flag = true;
                break;
            }
            if(i+1< (int)x.size()) ans*=10;
        }
        cout << "Ticket #" <<k << ":"<< "\n";
        if(flag) cout << ans << " " << ans2 << "\n";
        else cout << "Not relative" << "\n";
    }
    return 0;
}

