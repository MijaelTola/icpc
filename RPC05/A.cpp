#include<bits/stdc++.h>
using namespace std;

int m[400][400],s[400][400];
int v[400],v2[400];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		m[i][0]=s[i][j]=-1;
	}
	for(int i=0; i<n; i++){
		for(int j=1; j<=m; j++){
			cin>>m[i][j];
			s[i][j]=m[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=3; j<=m; j++){
			s[i][j]+=max(m[i][j-3],m[i][j-2]));
		}
	}
	v[0]=v2[0]=-1;
	for(int i=1; i<n; i++){
		v[i]=v2[i]=s[i][m];
	}
	int maxi=-1;
	for(int i=3; i<=m; i++){
		maxi=max(maxi,v[i]+=max(v2[i-3],v2[i-2]));
	}
	cout<<maxi<<"\n";
}
