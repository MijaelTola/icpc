#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int cases;
	cin>>cases;
	while(cases--){
		int n;
		cin>>n;
		pair<int,int>l,r,u,d;
		l={123123,0};
		r={-123123,0};
		u={0,-123123};
		d={0,123123};
		for(int i=0,uu,vv;i<n;i++){
			cin>>uu>>vv;
			if(uu<l.first){
				l={uu,vv};
			}
			if(uu>r.first){
				r={uu,vv};
			}
			if(vv>u.second){
				u={uu,vv};
			}
			if(vv<u.second){
				d={uu,vv};
			}
			cin>>uu>>vv;
			if(uu<l.first){
				l={uu,vv};
			}
			if(uu>r.first){
				r={uu,vv};
			}
			if(vv>u.second){
				u={uu,vv};
			}
			if(vv<u.second){
				d={uu,vv};
			}
			cin>>uu>>vv;
			if(uu<l.first){
				l={uu,vv};
			}
			if(uu>r.first){
				r={uu,vv};
			}
			if(vv>u.second){
				u={uu,vv};
			}
			if(vv<u.second){
				d={uu,vv};
			}
			cin>>uu>>vv;
			if(uu<l.first){
				l={uu,vv};
			}
			if(uu>r.first){
				r={uu,vv};
			}
			if(vv>u.second){
				u={uu,vv};
			}
			if(vv<u.second){
				d={uu,vv};
			}
		}
		//cout<<l.first<<" "<<r.first<<" "<<u.second<<" "<<d.second<<"\n";
		cout<<(abs(r.first-l.first)*abs(u.second-d.second))<<"\n";
	}
}
for(string u:st)cout<<u