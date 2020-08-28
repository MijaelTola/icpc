#include <iostream>

using namespace std;

int v[1000020];

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n and n){
		for (int i = 0; i < n; ++i) cin >> v[i];
		int ans = -1;
		int sum = 0;
		int a = 0;
		int b = n;
		int last = 0;
		for (int i = 0; i < n; ++i){
			sum += v[i];
			sum = max(sum,0);
			if(sum >= ans){
				ans = sum;
				b = i;
			}
		}
		int t = ans;
		for (a = b; ans != 0; a--)
			ans -= v[a];
		if(t != 0)	cout << t <<" "<< a+1 <<  " " <<  b << "\n";
		else cout << 0 << " " << -1 << " " << -1 << "\n";
	}
	return 0;
}
