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
#include <bitset>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
ll _sieve_size; // ll is defined as: typedef long long ll;
bitset<10000010> bs; // 10^7 should be enough for most cases
vi primes; // compata list of primes in form of vector<int>

void sieve(ll upperbound) { // create list of primes in [0..upperbound]
	_sieve_size = upperbound + 1; // add 1 to include upperbound
	bs.set(); // set all bits to 1
	bs[0] = bs[1] = 0; // except index 0 and 1
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
	// cross out multiples of i starting from i * i!
	for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
	primes.push_back((int)i); // add this prime to the list of primes
	} 
} // call this method in main method
bool isPrime(ll N) { // a good enough deterministic prime tester
if (N <= _sieve_size) return bs[N]; // O(1) for small primes
for (int i = 0; i < (int)primes.size(); i++)
if (N % primes[i] == 0) return false;
return true; // it takes longer time if N is a large prime!
}

ll sumDiv(ll N) {
	ll PF_idx = 0, PF = primes[PF_idx], ans = 1; // start from ans = 1
	while (PF * PF <= N) {
	ll power = 0;
	while (N % PF == 0) { N /= PF; power++; }
	ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);
	PF = primes[++PF_idx];
	}
	if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1); // last
	return ans;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	sieve(1e7);
	while(t--){
		ll n; 
		cin >> n;
		ll suma = sumDiv(n)-n;
		if(suma < n) cout << "deficient\n";
		if(suma == n) cout << "perfect\n";
		if(suma > n) cout << "abundant\n";
	}
    return 0;
}
