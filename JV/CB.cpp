#include <bits/stdc++.h>

using namespace std;

int main(){
	string x;
	int t;
	cin >> t;
	while(t--){
		cin >> x;
		int sum1 = 0,sum2 = 0;
		for (int i = 0; i < x.size(); i+=2)
			sum1 += x[i] - '0';
		for (int i = 1; i < x.size(); i+=2)
			sum2 += x[i] - '0';

		int ans = abs(sum1 - sum2);
		if(ans%11 == 0) cout << 'S';
		else cout << 'N';
		cout << endl;
	}
	return 0;
}