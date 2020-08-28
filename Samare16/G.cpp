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

int n,m,a,b;
multimap<ii,int> B;
vector<ii>A;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	FOR(i,0,n){
		cin>>a>>b;
		A.PB(MP(a,b));
	}
	cin>>m;
	FOR(i,0,m){
		cin>>a>>b;
		B.IN(MP(MP(a,b),i));
	}
	multimap<ii,int>::iterator it;
	vector<int>ans;
	FOR(i,0,n){
		cout<<A[i].F<<' '<<A[i].S<<'\n';
		it = B.lower_bound(MP(A[i].F,A[i].S));
		if(it==B.end()){
			cout<<-1<<'\n';
			return 0;
		}
		ans.PB(it->S);
		cout<<it->F.F<<" "<<it->F.S<<'\n';
		B.erase(it);
	}
	FOR(i,0,ans.size())cout<<ans[i]<<' ';cout<<'\n';
    return 0;
}
