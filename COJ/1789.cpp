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

typedef long long ll;

bool sieve[3010000];
vector<int> primes;
bool factor(ll n){
    set<ll> s;
    int index = 0;
    ll pf = primes[0];
    while(pf*pf <= n){
        while(n%pf!= 0){ n/=pf;s.insert(pf);}
        pf = primes[++index];
    }
    if(s.size() > 2) return false;
    return true;
}

void criba(){
    memset(sieve,false,sizeof sieve);
    for (int i = 2; i*i < 3010000; ++i){
     int c =i+ i;
        while(c < 3010000){
            sieve[c] = true;
            c += i;
        }
    }
    for (int i = 2; i < 3010000; ++i)
        if(!sieve[i]) primes.push_back(i);
}
int main(){
    criba();
    int t; cin >> t;
    while(t--){
        ll x; cin >> x;
        if(!sieve[x]){
            cout << "Vasha\n0\n";
            continue;
        }
    }
    return 0;
}

