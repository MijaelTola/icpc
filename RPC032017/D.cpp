#include <iostream>

using namespace std;


int t,n;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		int s = 0;
		for(int i = 1; i < n; i++){
			if(n%i==0)s+=i;
		}
		cout<<s<<'\n';
		if(s<n)cout<<"deficient\n";
		else if(s==n)cout<<"perfect\n";
		else cout<<"abundant\n";

		
	}
	return 0;
}
