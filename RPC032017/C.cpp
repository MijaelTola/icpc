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

const int mod = 1e9+7;

int prime[5010];
vector<int> primes;
long long dp[5010][5000];
pair<int,int> ans[5010][5010];
int d[5010];

long long f(int n, int k){
    if(k == 0 or n == k) return 1;
    if(dp[n][k] != -1) return dp[n][k];
    long long  ans = 0;
    ans = (ans+f(n-1,k-1))%mod;
    ans = (ans+f(n-1,k)%mod);
    return dp[n][k] = ans;
}
void criba(){
    memset(prime,0,sizeof prime);
    for(int i = 4; i < 5010; i += 2) prime[i] = 2;
    for (int  i = 3; i*i < 5010; i += 2){
        if(!prime[i]){
            for (int j = i*i; j < 5010; j += 2*i)
                prime[j] = i;
        }
    }

    for (int i = 2; i < 5010; ++i)
        if(!prime[i]) primes.push_back(i);
}

long long numDiv(int n){
    int idx = 0, pf = primes[idx], ans = 1;
    while(pf*pf <= n){
        long long power = 0;
        while(n%pf==0){n/=pf; power++;}
        ans *= (power+1);
        pf = primes[idx++];
    }
    if(n != 1) ans *= 2;
    return ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    memset(dp,-1,sizeof dp);
    criba();
    f(5000,5000);
    for (int i = 1; i < 5010; ++i){
        d[i] = numDiv(i)-1;
    }
    
    for (int k = 1; k < 5010; ++k){
        int sum = 0;
        int m = 1;
        for (int n = 1; n < 5010; ++n){
            int nd = d[n];
            if(nd > k){
                sum += k;
                m = (m*f(nd,k))%mod;
            }else sum += nd;
            ans[n][k] = {sum,m};
        }
    }
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        cout << ans[n][k].first << " " << ans[n][k].second << "\n";
    }
    return 0;
}

