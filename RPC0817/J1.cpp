#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<pair<int, int> > E;
	vector<pair<int, int> > D;
	int n;
	cin>>n;
	for(int i=0; i<n;i++){
		int x,y;
		cin>>x>>y;
		E.push_back(make_pair(x,y));
	}
	for(int i=0; i<n;i++){
		int x,y;
		cin>>x>>y;
		D.push_back(make_pair(x,y));
	}
	int M[110][110];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			M[i][j]=abs(E[i].first-D[j].first)+abs(E[i].second-D[j].second);
		}
	}
	for(int i=0; i<n; i++){
		for (int j = 0; j < n; ++j)
		{
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
	int maxN=-1;
	int minN=100000000;
	int indexmaxi, indexmaxj, indexmini, indexminj;
	int ans=-1;
	for(int k=0; k<n; k++){
		for(int i=0; i<n;i++){
			for(int j=0; j<n; j++){
				if(maxN<M[i][j]){
					indexmaxi=i;
					indexmaxj=j;
					maxN=M[i][j];
				}
			}
		}
        
	}
	

	cout<<indexmini<<"   "<<indexminj<<endl;
	cout<<indexmaxi<<"   "<<indexmaxj<<endl;
	return 0;
}
