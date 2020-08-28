#include <bits/stdc++.h>
using namespace std;


int t,e,f,c,s;
int main(){
	cin>>t;
	while(t--){
		cin>>e>>f>>c;
		if(c==1){
			cout<<"0\n";
			continue;
		}
		s=e+f;
		int res = 0, ans = 0;
		while(true){
			ans+=s/c;
			res = s%c;
			s/=c;
			s+=res;
			if(s<c)break;
		}
		cout<<ans<<"\n";
	}
	
  
	return 0;
}
