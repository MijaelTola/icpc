#include <bits/stdc++.h>
using namespace std;
typedef  double rl;
const rl eps=0.0000001;
const int NN=410;
rl S[6]={4.0, 6.0, 8.0, 10.0, 12.0, 20.0} ;
int S2[6]={4, 6, 8, 10, 12, 20} ;
int I[21];
rl M[NN][21][6];
rl f(int h, int k, int s){
	if(h<=0){
		return 1.0;
	}
	if(k==0){

		return 0.0;
	}
	if( M[h][k][s]>-1.0)return M[h][k][s];
	M[h][k][s]=0.0;
	for(int i=1;i<=S2[s];i++){
		M[h][k][s]+=f(h-i,k-1,s);
	}
	M[h][k][s]/=S[s];
	return M[h][k][s];
}
int main(){
	I[4]=0;
	I[6]=1;
	I[8]=2;
	I[10]=3;
	I[12]=4;
	I[20]=5;
	int n,h,a,b,c,sig;
	string s;
	int test;
	cin>>test;
	for(int i=0;i<NN;i++)
		for(int j=0;j<21;j++)
			for(int k=0;k<6;k++)
				M[i][j][k]=-2.0;


	for(int te=1;te<=test;te++){
		cin>>h>>n;
		rl mx=0.0;
		double res;
		for(int i=0;i<n;i++){
			cin>>s;			
			s+=" 0";			
			sig=1;
			for(int j=0;j<s.size();j++){
				if(s[j]=='d')s[j]=' ';
				if(s[j]=='-'){
					sig=-1;
					s[j]=' ';
				}
				if(s[j]=='+')s[j]=' ';
			}
			stringstream st;
			st<<s;
			st>>a;
			st>>b;
			st>>c;
			//printf("%.10lf ", f(h-c*sig,a,I[b]));
			if(h-c*sig<=a*b) res= f(h-c*sig,a,I[b]);
			else res=0.0;
			mx=max(mx,res);
		}
		printf("Case #%d: %.6lf\n",te,mx );
	}
	return 0;
}
