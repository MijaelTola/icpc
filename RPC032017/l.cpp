#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, n;
	scanf("%d",&t);
	while(t--){
		deque<int> v;
		scanf("%d",&n);
		//cout<<"n = "<<(n&(1<<0))<<'\n';
		int e1, e2, e3;
		int sw = 0;
		for(int i = 31; i >= 0; i--){
			if(sw > 0){
				sw++;
				v.push_back((n&(1<<i))?1:0);
				if(sw == 2) e2 = ((n&(1<<i))?1:0);
				if(sw == 3) e3 = ((n&(1<<i))?1:0);
			}else{
				if(n&(1<<i)){
					sw = 1;
					v.push_back(1);
					e1 = 1;
				}
			}
		}
		//cout<<e1<<' '<<e2<<' '<<e3<<'\n';
		v.push_back(e1);
		v.push_back(e2);
		v.push_back(e3);

		vector<int> vec;
		int a;
		while(!v.empty()){
			a = v.front(); v.pop_front();
		    vec.push_back(a);
		}

		int r, c = 0;
		for(int i = 2; i < vec.size(); i++){
			r = 0;
			if(vec[i-2]) r|= 1<<2;
			if(vec[i-1]) r|= 1<<1;
			if(vec[i]) r|= 1<<0;
			//cout<<r<<endl;
			c |= (1<<r);
		}

		//cout<<c<<'\n';
		//cout<<(1<<8)-1<<'\n';
		if(c == (1<<8)-1) printf("yes\n");
		else printf("no\n");
											   
		
	}
	
	return 0;
}
