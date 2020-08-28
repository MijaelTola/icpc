#include <iostream>
#include <climits>
using namespace std;

typedef unsigned long long ull;
int main(){
	
	ull n; 
	int t; scanf("%d",&t);
	while(t--){
	scanf("%lld",&n);
	ull a = -1; ull b = 1e10;
	while(b-a>1LL){
		ull mid = (a+b)>>1LL;
		if(mid*(mid+1LL)/2LL > n) b = mid;
		else a = mid;
	} 
	if(n == (a*(a+1))/2LL) printf("Go On Bob %lld\n",a);
	else if(n == (b*(b+1))/2LL)printf("Go On Bob %lld\n",b);
	else printf("Better Luck Next Time\n");
	}
	return 0;
}
