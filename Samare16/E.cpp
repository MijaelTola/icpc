#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
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
typedef tree<
	ii,
	null_type,
	less<ii>,
	rb_tree_tag,
	tree_order_statistics_node_update> ordered_set;

int n,l,r;
ordered_set s;
vector<ii>v;
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	FOR(i,0,n){
		cin>>l>>r;
		v.PB(MP(l,r));
	}
	sort(v.begin(),v.end());
	int ans = 1,cont = 1;
	s.IN(MP(v[0].S,cont++));
	int sum = 1;
	FOR(i,1,n){
		int c = s.order_of_key(MP(v[i].F,INT_MIN));
		//cout<<i<<' '<<c<<'\n';	
		ans = (sum-c)+1;
		s.IN(MP(v[i].S,cont++));
		sum++;
	}
	cout<<ans<<'\n';
    return 0;
}
