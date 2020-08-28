#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);	
	double d,n;
	while(cin >> d >> n){
		v.clear();
		double fr = 0;
		for(int i = 0; i < n; ++i){
			int x; cin >> x;
			fr += x;
			v.push_back(x);
		}
		double sum = 0;
		sort(v.rbegin(),v.rend());
		for (int i = 0; i < n; ++i){
		    double a = (v[i]*(i+1)* d)/fr;
		  //  cout << a << endl;
	 	    sum += a;
		}
		cout.precision(4);
		cout<<fixed << sum << endl;
	}
	return 0;
}
