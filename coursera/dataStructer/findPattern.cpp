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

using namespace std;

typedef long long ll;

void RabinKarpMatching(string T, string P, int d, int q){
    int n = T.size();
    int m = P.size();
    int h = 1;
    for (int i = 1; i < m; ++i) 
        h = (h*d)%q;
    int p = 0;
    int t = 0;
    for (int i = 0; i < m; ++i){
        p = (d*p+P[i])%q;
        t = (d*t+T[i])%q;
    }
    vector<int> ans;
    for (int s = 0; s <= n-m; ++s){
        if(p == t){
            bool flag = true;
            for (int j = 0; j < m; ++j){
                if(T[s+j] != P[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(s);
        }
        if(s < n-m){
            t =(d*(t-T[s]*h) + T[s+m])%q;
            if(t < 0) t += q;
        }
    
    }
    for (int i = 0; i < (int)ans.size(); ++i) cout << ans[i] << " ";
}
int main(){
    string p,t;
    cin >> p >> t;
    RabinKarpMatching(t,p,256,101);
    return 0;
}

