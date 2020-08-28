#include <iostream>

using namespace std;

int v[100010];

int main(){
	
	int n; cin >> n;
	
	for (int i = 0; i < n; ++i) cin >> v[i];
	cout << v[0] << " ";
	for (int i = 1; i < n; ++i) cout << v[i] - v[i-1] << " ";
	return 0;
}
