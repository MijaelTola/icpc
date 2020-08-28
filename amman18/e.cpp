#include <bits/stdc++.h>

using namespace std;

int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

const int mod = 1e9 + 7;
long long v[100010];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; t = in();
	while(t--) {
		int n; n = in();		
		for (int i = 0; i < n; ++i) 
			v[i] = in();
		
		long long ans = v[0] - 1;	
		long long mul = v[0];
	
		for (int i = 1; i < n; ++i) {
			ans = ((ans % mod) * (v[i])) % mod;
			ans = (ans + (((v[i] - 1) * mul) % mod)) % mod;
			mul = (mul * v[i]) % mod;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}

