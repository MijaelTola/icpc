#include <bits/stdc++.h>

using namespace std;

int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
const int lim = 1000000;

int Primes[lim + 10];
vector<int>P,v;
int b, n;
unordered_map<long long,int> mp;
int sz;
int dp[50001][1010];
const int mod = 1e9 + 7;

int f(int pos, int db) {
	if (db > b)return 0;
	if(pos == sz) return db == b;
	int &ans = dp[pos][db];
	if(ans != -1) return ans;
    ans = 0;
    for (int i = 1; i <= v[pos]; ++i) 
        ans = (ans + f(pos + 1, db * (i + 1))) % mod;
    ans = (ans + f(pos + 1, db)) % mod;
	return ans;
}

int main() {
	Primes[0] = Primes[1] = 1;
	for (int i = 2; i <= lim;i++) {
		if (!Primes[i])
			for (int j = i + i; j <= lim; j+=i) {
				Primes[j] = 1;
			}
	}
	P.push_back(2);
	for (int i = 3; i <= lim;i++)if (!Primes[i])P.push_back(i);
	b = in(), n = in();
	long long u;
	for (int i = 0; i < n;i++) {
		scanf("%lld", &u);
		long long PF = P[0], pos = 0;
		while (PF * PF <= u && pos < (int)P.size()) {
			if (u % PF == 0) {
				int c = 0;
				while (u % PF == 0) {
					u /= PF;
					c++;
					v.push_back(c);
				}
			}
			PF = P[++pos];
		}
		if (u != 1LL) v.push_back(1);
	}
	
	sz = v.size();
	//cout << sz << endl;
	memset(dp, -1, sizeof dp);
	cout << f(0, 1) << "\n";
	return 0;
}
