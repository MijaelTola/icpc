#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	double n;
	while(cin >> n){
	a.clear();
	//cout << "adfasdf " << endl;
	for (int i = 0; i < n; ++i){
	     int x; cin >> x;
	     a.push_back(x);	
	}
	//cout << "asdfasdf" << endl;
	sort(a.rbegin(),a.rend());
	double sum = 0;
	for (int i = 0; i < a.size();++i)
	    sum += (i+1)*a[i];
	cout.precision(4);
	cout <<fixed << sum/n << "\n";
	}
	return 0;
}
