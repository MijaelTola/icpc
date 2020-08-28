#include <iostream>

using namespace std;

int p[100010];
int s[100010];
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n,m,q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i){
		int x; cin >> x;
		s[i] = x;
		p[x]++;
	}o
	int count = 0;
	for (int i = 1; i <= m; ++i)
		if(p[i] > 0) count++;
	for (int i = 0; i < q; ++i){
		int x,y; cin >> x >> y;
		int care = s[x];
		p[care]--;
		s[x] = y;
		if(p[care] == 0) count--;
		p[s[x]]++;
		if(p[s[x]] == 1) count++;
		cout << m - count << "\n";
	}
	return 0;
}
