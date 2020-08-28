#include <bits/stdc++.h>

using namespace std;
int n;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//cout<<(char)(25-'d')<<'\n';
	//cout<<'a'-'y'<<"\n";
	cin>>n;
	int div = n/25;
	//cout<<div<<'\n';
	if(div==0){
		cout<<"a"<<(char)('a'+n)<<"\n";
		return 0;
	}
	// if(div==1){
	// 	int mid = n/2;
	// 	if(n%2!=0){
	// 		mid++;
	// 		cout<<"a"<<(char)('a'+mid)<<"b";
	// 	}else{
	// 		cout<<"a"<<(char)('a'+mid)<<"a";
	// 	}
	// 	return 0;
	// }
	string sol = "a";
	for(int i = 0; i < div; i++){
		if(i%2==0)sol+="z";
		else sol+="a";
	}
	//	cout<<sol<<"\n";
	if(n%25!=0){
		int mod = n%25;
		int dif = (25-mod)/2;
		sol[1]=(char)('z'-dif);
		if(div%2==0){
			sol+=(char)('a'+(dif*2)+mod);
		}else{
			sol+=(char)('z'-(dif*2)-mod);
		}
	}
	cout<<sol<<"\n";
	 
	return 0;
}
