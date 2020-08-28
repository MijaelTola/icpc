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
#include <cmath>
#include <deque>
#include <string> 
#include <sstream>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool vis[1010];
int main(){
    //ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    for (int caso = 1; caso <= t; ++caso){
        long long n,k; cin >> n >> k;
        memset(vis,false,sizeof vis);
        vis[1] = true;
        vis[n+2] = true;    
        
        int mn = -1;
        int mx = 1e9;
        for (int i = 0; i < k; ++i){
            mn = -1;
            mx = 1e9;
            int cur = 0;
            int l = 1;
            int r = 1;
            for (int j = 1; j <= n + 2; ++j){
                if(vis[j]){
                    r = j;
                    for (int k = l+1; k < r; ++k){
                        int mnn = min(k-l,r-k);
                        int mxx = max(k-k,r-k);
                        if(mnn > mn){
                            mn = mnn; 
                            mx = mxx;
                            cur = k;
                        }else if(mnn == mn and mxx > mx){
                            mn = mnn; 
                            mx = mxx;
                            cur = k;
                        }
                    }
                    l = j;
                }
            }
            vis[cur] = true;
        }

        long long p = n/sqrt(k);
        cout << mx-1 << " " << mn-1 << " " << p/2 << " " << p/2-1 << "\n";
    }
    return 0;
}

