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

long long mod = 1000000007LL;
long long modpow(long long b, long long e){
    long long x = 1, y = b;
    while(e>0){
        if(e%2==1) x = (x*y)%mod;
        y = (y*y)%mod;
        e/=2;
    }
    return x%mod;
}

long long C2(long long a){
    return (((a*(a-1))%mod)*modpow(2LL,mod-1LL))%mod;
}

long long C3(long long a){
    return ((((a*(a-1)%mod)*(a-2))%mod)*modpow(6LL,mod-1LL))%mod;
}

long long solve(long long n){
    long long m = (n/2LL+1LL)%mod;
    long long e = (n-m+1LL)%mod;
    long long s = (m*((m*(m-1LL))/2LL+1LL+((m+1LL)*m)/2LL))/2LL;
    long long ans = s*e;
    ans += m*(((e*(e-1LL))/2LL)*m+((e+1)*(e)*(e-1LL))/6LL);
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    for (int i = 1; i <= t; ++i){
        long long x;
        scanf("%lld",&x);
        printf("Case #%d: %lld\n",i,solve(x));
    }
    return 0;
}

