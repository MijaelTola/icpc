#include <bits/stdc++.h>

using namespace std;


string cad;
int main(){
	getline(cin,cad);
	int a = cad[0]-'0';
	int b = cad[4]-'0';
	int r = cad[8]-'0';
	//cout<<cad[0]<<' '<<cad[4]<<" "<<cad[8]<<"\n";
	//cout<<a<<" "<<b<<" "<<r<<"\n";
	if(a+b==r)cout<<"YES\n";
	else cout<<"NO\n";
	
	
	return 0;
}
