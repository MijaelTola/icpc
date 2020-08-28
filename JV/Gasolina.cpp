#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll v[100010];

int main(){
	int x,d,n;
	
	while(cin >> x >> d >> n){
		for (int i = 0; i < n; ++i) cin >> v[i];
		v[n] = d;
		n++;
		sort(v,v+n);
		int ans = 0;
		int distance = x;
		for (int i = 0; i < n; ++i)
			if(distance < v[i+1]){
				ans++;
				distance = x+v[i];
			}
		cout << ans << endl;
	}
	return 0;
}
