#include <bits/stdc++.h>
using namespace std;
long long v[3];
long long ans[15];
long long a,b,c;	
void f(int n){
	if(n == 10)	
		return;
	for(int i = 0; i<3; i++){
		v[i]++;		
		long long temp = (v[0]*v[0]) + (v[1]*v[1]) + (v[2]*v[2]) + 7*min(v[0], min(v[1], v[2]));
		if(n == 9 and temp > ans[n]) {
			a = v[0], b = v[1], c = v[2];
		}
		ans[n] = max(ans[n], temp);	
		f(n+1);
		v[i]--;
	}
}
int main(){
	memset(ans, 0, sizeof(ans));
	long long d;
	
	int t; cin >> t;
	while(t--) {
	memset(ans, 0, sizeof ans);
	cin>>v[0]>>v[1]>>v[2]>>d;
		
	f(0);
	
	if(d <= 9){
		if(d == 0){
			cout<<(v[0]*v[0]) + (v[1]*v[1]) + (v[2]*v[2]) + 7*min(v[0], min(v[1], v[2]))<<endl;
		}
		else
			cout<<ans[d-1]<<endl;
		continue;
	}
	//v[0] = a;
	//v[1] = b;
//	v[2] = c;
	sort(v,v+3);
	d = d;
	v[2]+=d;
	cout<<(v[0]*v[0]) + (v[1]*v[1]) + (v[2]*v[2]) + 7*min(v[0], min(v[1], v[2]))<<endl;
	}
}
