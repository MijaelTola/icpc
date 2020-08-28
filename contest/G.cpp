#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	char c[100][100];
	while(cin>>n){
		if(n==0) break;
        cin >> s;
		int q=0;
		int w=ceil(s.length()/n);
		int e=0;
		for(int i=0;i< (int)s.length(); i+=n){
			if(i%2==0){
				for(int j=0; j<n; j++){
					c[q][j]=s[e];
	//				cout<<c[q][j]<<" ";
					e++;
				}	
			}else{
				int r=0;
				for(int j=n; j>=1; j--){
					c[q][r]=s[e+j];
	//				cout<<c[q][r]<<"  ";
					r++;

				}
				e+=n;
			}
			q++;
		}
		//cout<<endl;
		for(int i=0; i<n; i++){
			for(int j=0; j<w; j++){
				cout<<c[j][i];
			}
			
		}
		cout<<endl;
	}
	return 0;
}
