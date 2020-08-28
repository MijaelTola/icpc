#include <bits/stdc++.h>
using namespace std;
int p[200010];
map<int,int>X,Y;
int comp;
void inic(int n){
	for(int i=0;i<n;i++)p[i]=i;
	comp=n;
}
int findSet(int i) {
  return p[i] == i?i:p[i] = findSet(p[i]);                                           
}
bool isSameSet(int i, int j) {
  return findSet(i) == findSet(j);
}
void unionSet(int i, int j) { 
	if(!isSameSet(i, j)) comp--;
	p[findSet(i)] = findSet(j);
}
int main(){
	int n;
	cin>>n;
		X.clear();Y.clear();
		inic(n);
		int m,x,y;
		for(int i=0;i<n;i++){
			cin>>x>>y;
			if(X.count(x)>0)
				unionSet(i,X[x]);
			if(Y.count(y)>0)
				unionSet(i,Y[y]);
			X[x]=i;
			Y[y]=i;
		}
//		cout<<comp<<endl;
		cin>>m;
		double s=comp,M=m;
		int k=n;
		while(m--){
			cin>>x>>y;
			if(X.count(x)>0 or Y.count(y)>0){
				unionSet(X[x],Y[y]);
				p[k]=findSet(X[x]);
				X[x]=k;
				Y[y]=k;
			}else{
				p[k]=k;
				X[x]=k;
				Y[y]=k;
				comp++;
			}
			k++;
			s+=(double)comp;
//			cout<<comp<<endl;
		}
		printf("%.2lf\n",s/(M+1));
	
	return 0;
}
