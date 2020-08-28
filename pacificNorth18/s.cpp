#include <bits/stdc++.h>

using namespace std;

int main () {
	string x; 
	cin >> x;
	int ans = -1;
	int sum = 0;
	
	int l = 0, r = 0;
	int al = -1, ar = -1;
	for (int i = 0; i < (int)x.size(); ++i) {
		sum += (x[i] == 'R') ? 1:-1;
		r++;
		if(sum < 0) {
			sum = 0;
			l = i + 1;
			r = i + 1;
		}
		if(sum > ans) {
			ans = sum;
			al = l + 1;
			ar = r;
			
		}
	}
	sum = 0;
	int ans2 = 0;
	l = 0, r = 0;
	int al2 = -1; 
	int ar2 = -1;
	for (int i = 0; i < (int)x.size(); ++i) {
		sum += (x[i] == 'B') ? 1:-1;
		r++;
		if(sum < 0) {
			sum = 0;
			l = i + 1;
			r = i + 1;
		}
		if(sum > ans2) {
			ans2 = sum;
			al2 = l + 1;
			ar2 = r;
			
		}
	}
	//cout << ans << " " << al << " " << ar << endl;
	if(ans2 > ans) cout << al2 << " " << ar2 << endl;
	else  if (ans == ans2) {
			if (al < al2) {
				cout << al << " " << ar << endl;
			} else cout << al2 << " " << ar2 << endl;
		}else cout << al << " " << ar << endl;
	return 0;
}
