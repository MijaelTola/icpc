#include <bits/stdc++.h>
using namespace std;

int t,n,m,cont[150],d;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(cont,0,sizeof cont);
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cin>>d;
				cont[j]+=d;
			}
		}
		int ans = -1, maxi=0;
		for(int i = 0; i < n; i++){
			if(maxi < cont[i]){
				maxi = cont[i];
				ans = i;
			}
		}
		cout<<ans+1<<"\n";
		
	}	
	
	
	return 0;
}
