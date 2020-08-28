#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll k, p, x;
	cin >> k >> p >> x;
	double mini = LLONG_MAX;
	int m = 1;
	while(true){
		double tmp1 = (double)((double)(k * p)/ (double)m);
		double tmp2 = (double) (x * m);
		tmp1 += tmp2;
		if(tmp1 > mini)
			break;
		mini = tmp1;
		m++;
	}
	
	cout.precision(3);
	cout << fixed << mini << endl;
}
