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
#include <bitset>

using namespace std;

typedef long long ll;

bitset<1000000010> bs;
vector<ll> primes;
int main(){
    ll sz = 1000000010;
    bs.set();
    bs[0] = bs[1] = 0;

    for (ll i = 2LL; i <= sz; ++i)if(bs[i]){
        for (ll j = i*i; j <= sz; j+=i) bs[j] = 0;
        primes.push_back(i);
    }
    
    ll a = -1;
    ll b = 1000000000;
    cout << "end" << endl;
    int t; cin >> t;
    while(t--){
        while(b-a > 1){
            ll mid = (a+b)/2LL;
            if(primes[mid] > b) b = mid;
            else a = mid;
        }
        cout << primes[b] << endl;
    }
    return 0;
}

