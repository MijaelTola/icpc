#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

int main(){
	int k;
	scanf("%d",&k);
	while(k--){
		ll n,x,t,r;
		scanf("%lld %lld %lld %lld",&n,&x,&t,&r);
		if(n <= x){
			printf("Construye 0 Colossus\n");
			continue;
		}
		n -= x;
		ll a = -1LL; ll b = t;
		while(b-a>1){
			ll mid = (a+b)>>1;
			if((mid*(mid+1))/2LL >= n) b = mid;
			else a = mid;
		}
		if(b*r <= t)printf("Construye %lld Colossus\n",b);
		else printf("GGWP\n");
	}
	return 0;
}
