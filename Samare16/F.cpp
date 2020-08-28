#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>ii;
#define PB push_back
#define MP make_pair
#define IN insert
#define F first
#define S second
#define FOR(i, c, n) for(int i = c; i < (int)n ; i++)
#define FOREARCH(i, v) for (__typeof(v.begin()) i = v.begin(); i != v.end(); i++)
#define BACEARCH(i, v) for (__typeof(v.rbegin()) i = v.rbegin(); i != v.rend(); i++)
//--------Main---------//

int n,a,b,c;
vector<pair<int,pair<int,ii> > >v;
vector<ii>A,B,C;
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	FOR(i,0,n){
		cin>>a>>b>>c;
		v.PB(MP(a,MP(b,MP(c,i))));
		A.PB(MP(a,i));
		B.PB(MP(b,i));
		C.PB(MP(c,i));
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	sort(C.begin(),C.end());
	FOR(i,0,n)cout<<A[i].F<<' '<<A[i].S<<'\n';
	vector<int>ans;
	FOR(i,0,n){
		int cont = 0;
		a = v[i].F;
		b = v[i].S.F;
		c = v[i].S.S.F;
		int ie= v[i].S.S.S;

		cout<<a<<' '<<b<<' '<<c<<" "<<ie<<'\n';

		int p = lower_bound(A.begin(),A.end(),MP(a,ie))-A.begin();
		if(p!=0)cont++;
		p = lower_bound(B.begin(),B.end(),MP(a,ie))-B.begin();
		if(p!=0)cont++;
		p = lower_bound(C.begin(),C.end(),MP(a,ie))-C.begin();
		if(p!=0)cont++;

		p = lower_bound(A.begin(),A.end(),MP(b,ie))-A.begin();
		if(p!=0)cont++;
		p = lower_bound(B.begin(),B.end(),MP(b,ie))-B.begin();
		if(p!=0)cont++;
		p = lower_bound(C.begin(),C.end(),MP(b,ie))-C.begin();
		if(p!=0)cont++;

		p = lower_bound(A.begin(),A.end(),MP(c,ie))-A.begin();
		if(p!=0)cont++;
		p = lower_bound(B.begin(),B.end(),MP(c,ie))-B.begin();
		if(p!=0)cont++;
		p = lower_bound(C.begin(),C.end(),MP(c,ie))-C.begin();
		if(p!=0)cont++;

		if(cont<2)ans.PB(ie);
	}
	cout<<"----\n";
	cout<<ans.size()<<'\n';
	FOR(i,0,ans.size())cout<<ans[i]<<' ';cout<<'\n';
	
    return 0;
}
