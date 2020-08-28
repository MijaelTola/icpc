#include <bits/stdc++.h>
//1798
using namespace std;
vector<pair<int,int> > v;
#define MAX_N 100005
#define f first 
#define s second
int A[MAX_N], L[MAX_N], L_id[MAX_N], P[MAX_N];

bool cmp(pair<int,int> a1, pair<int,int> b1){
	if(a1.second != b1.second)
		return (a1.second < b1.second);
	return (a1.first > b1.first);
}

int main(){
	int cases;
	cin>>cases;
	while(cases--){
	 	v.clear();
	 	int n, tmp,a ,b ;
	 	cin>>n;
	 	memset(L,0,sizeof(L));
	 	for(int i = 0; i < n; i++){
	 		cin>>a>>b;
	 		v.push_back(make_pair(a,b));
	 	}
	 	sort(v.begin(),v.end(),cmp);
	 	for(int i = 0; i < n;i++){
	 		A[i] = -v[i].f;
	 	}
	 	int lis = 0, lis_end = 0;
	 	for (int i = 0; i < n; i++) {
	 		int pos = upper_bound(L, L + lis, A[i]) - L;
	 			L[pos] = A[i];
	 			L_id[pos] = i;
	 			P[i] = pos ? L_id[pos - 1] : -1;
	 			if (pos + 1 > lis) {
	 				lis = pos + 1;
	 				lis_end = i;
	 			}
	 	}
		cout<<lis<<endl;
	}
	return 0;
}
