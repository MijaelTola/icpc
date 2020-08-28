#include <bits/stdc++.h>

using namespace std;
const int lim = 100;
int m[110][110];
bool check[lim * lim + 10];
int f(int r, int c) {
	memset(check,0,sizeof check);
	for (int i = 0; i < r;i++)check[m[i][c]] = 1;
	for (int i = 0; i < c;i++)check[m[r][i]] = 1;
	int pos = 1;
	while (pos <= r && pos <= c) {
		check[m[r - pos][c - pos]] = 1;
		pos++;
	}
	for (int i = 0; i <= lim * lim;i++)if (!check[i])return i;
}
int main() {
	memset(m, 0, sizeof m);
	for (int i = 0; i <= lim;i++)m[i][0] = m[0][i] = m[i][i] = lim * lim - 1;
	// cout << " MY " << m[0][0] << endl;
	for (int i = 1; i <= lim;i++)
		for(int j = 1; j <= lim; j++)
			if (i != j)m[i][j] = f(i, j);
	/*
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10; j++)
			cout << m[i][j] << " ";
			cout <<endl;
		}
		*/
	int n; cin >> n;
	int ans = 0;
	while(n--) {
		int x,y;
		cin >> x >> y;
		if (m[x][y] == lim * lim - 1)return cout << "Y\n",0;
		ans ^= m[x][y];
	}
	if (ans)cout << "Y\n";
	else cout << "N\n";
	return 0;
}
