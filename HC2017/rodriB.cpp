#include <bits/stdc++.h>
using namespace std;
multiset<int>S;
int main(){
	int test,n,x;
	cin>>test;
	for(int te=1;te<=test;te++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x;
			S.insert(-x);
		}
		int c=0,t;
		//cout<<(int)S.size()<<endl;
		set<int>::iterator it;
		while((int)S.size()>0){
			x=*S.begin();
			x*=-1;
			S.erase(S.begin());
			t=1;
			while(t*x<50 and (int)S.size()>0){
				it=S.end();
				it--;
				S.erase(it);
				t++;
			}
			//cout<<x<<" "<<t<<" "<<(int)S.size()<<endl;
			if(t*x>=50)c++;
		}
		printf("Case #%d: %d\n",te,c );
	}
	return 0;
}
