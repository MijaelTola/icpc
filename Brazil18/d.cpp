#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,tmp,ans = 0;
	cin>>n;
	while(n--){
		cin>>tmp;
		if(tmp != 1)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
