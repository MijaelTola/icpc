#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n,m,k,t;
	bool dm[105][105];
	memset(dm, false, sizeof dm);
	cin >> n >> m >> k >> t;
	for (int i = 0; i < k; ++i)
	{
		int  x,y;
		cin >> x >> y;
		dm[y-1][x-1] = true;
	}

	/*for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << dm[i][j];
		}
		cout << endl;
	}*/
	int ans = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int c = 0;
			for (int s = 0; s <= i; ++s)
			{
				for (int p = 0; p <= j; ++p)
				{
					//cout << dm[s][p];
					if(dm[s][p]) c++;
				}
			//	cout << endl;
			}
			if(c == t) ans++;
		//	cout << "asdf" << " " << c << endl;
		}
	}

	cout << ans;
	return 0;
}
