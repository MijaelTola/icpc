#include <iostream>
#include <cstdio>
using namespace std;
#include <vector>
int parent[200010];
int n,sz;
void init(int n){sz=n;for(int i=0;i<=200000;i++)parent[i]=i;}
int find(int u){return u==parent[u]?u:parent[u]=find(parent[u]);}
typedef bool boid;
boid Union(int u,int v){
	int pu=find(u),pv=find(v);
	if(pu==pv)return false;
	parent[pv]=pu;
	sz--;
	return true;
}
boid Uniona(int u,int v){
	int pu=find(u),pv=find(v);
	if(pu==pv)return false;
	parent[pv]=pu;
	return true;
}
vector<int>Gx[100010],Gy[100010];
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);
	int n;
	cin>>n;
	init(n);
	for(int i=0,u,v;i<n;i++){
		cin>>u>>v;
		Gx[u].push_back(i);
		Gy[v].push_back(i);
	}
//	cout<<Gx[0].size()<<endl;
	for(int i=0;i<=100000;i++){

		for(int j=1;j<Gx[i].size();j++){
			Union(Gx[i][j],Gx[i][j-1]);
		//	cout<<Gx[i][j-1]<<" "<<Gx[i][j]<<endl;
		}
		for(int j=1;j<Gy[i].size();j++){
			Union(Gy[i][j],Gy[i][j-1]);
		//	cout<<Gy[i][j-1]<<" "<<Gy[i][j]<<endl;
		}
	}
//	cout<<sz<<endl;
	int M;
	cin>>M;
	double sum=sz;
	for(int i=0,u,v;i<M;i++){
		cin>>u>>v;
		//sz++;
		bool check=false;
		if(Gx[u].size()){
			check=true;
			Uniona(Gx[u][0],n+i);	
		}
		if(Gy[v].size()){
			if(find(n+i)==find(Gy[v][0])){}
				else{
			Uniona(Gy[v][0],n+i);
			if(check)sz--;
			check=true;
		}
		}
		if(!check)sz++;
		sum+=sz;
	/*	for(int t=0;t<n+i+1;t++){
			find(t);
			cout<<parent[t]<<" ";
		}cout<<"\n";*/
		Gx[u].push_back(i+n);
		Gy[v].push_back(i+n);
	}
	//cout<<endl;
	double m=M+1.0;
	cout.precision(2);
	cout<<fixed<<sum/m;
	//cout<<sum<< " "<< m<<"\n";
	//cout<<"asdf "<<sum/(m+1)<<"\n";
}
