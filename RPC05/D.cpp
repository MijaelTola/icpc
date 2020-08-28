#include <iostream>

using namespace std;

int main(){
	int n,t; cin >> t;
	while(t--){
		cin >> n;
		cout << (n*n*n*n-6*n*n*n+23*n*n-18*n+24)/24 << "\n";
	}
	return 0;
}
