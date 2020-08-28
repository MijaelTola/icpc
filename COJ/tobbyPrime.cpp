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

using namespace std;

typedef long long ll;

const ll mod = 1000000007;
bool sieve[5000];
ll dp[510][2][5000];
string number;
ll f(int pos, int flag, ll sum){
    if(pos == (int)number.size()){
        if(!sieve[sum]) return 1LL;
        return 0;
    }
    if(dp[pos][flag][sum] != -1) return dp[pos][flag][sum];
    ll ans = 0;   
    if(!flag){
        for (int i = 0; i < 10; ++i)
            ans += f(pos+1,false,sum+i)%mod;
    }else{
        for (int i = 0; i < number[pos]-'0'; ++i)
            ans += f(pos+1,false,sum+i)%mod;
        ans += f(pos+1,true,sum+(number[pos]-'0'))%mod;
    }
    return dp[pos][flag][sum] = ans;
}
void substract(){
    bool pivot = false;
    for (int i = number.size(); i >= 0; --i){
        if(pivot) number[i]--;
        if(number[i] < '0') number[i] = '9', pivot = true;
        else pivot = false;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    memset(sieve,false,sizeof sieve);
    sieve[0] = sieve[1] = true;
    for (int i = 2; i*i < 5000; ++i){
        int c = i+i;
        while(c < 5000){
            sieve[c] = true; c += i;
        }
    }
    while(cin >> number){
        substract();
        memset(dp,-1,sizeof dp);
        ll ans1 = f(0,1,0);
        cin >> number;
        memset(dp,-1,sizeof dp);
        ll ans2 = f(0,1,0);
        cout << (ans2-ans1+mod)%mod << "\n";
    }
    return 0;
}

