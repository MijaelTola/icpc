#include <bits/stdc++.h>

using namespace std;

int dx[8] = {1,2,1,-1,-2,-2,-1,2};
int dy[8] = {2,-1,-2,-2,-1,1,2,1};

int main(){
	bool m[110][110];
	memset(m,false,sizeof m);
	int n,r;


	cin >> n >> r;
	vector<pair<int,int> > v;
	for (int i = 0; i < r; ++i)
	{
		int x,y;
		cin >> x >> y;
		m[y][x] = true;
		v.push_back(make_pair(y,x));
	}
	for (int i = 0; i < v.size(); ++i)
	{
		int x = v[i].first;
		int y = v[i].second;
	//	cout << x << " " << y <<": " <<endl;
		for (int j = 0; j < 8; ++j)
		{
			int t = x + dx[j];
			int s = y + dy[j];
			if(t > 0 and s > 0 and t <= n and s <= n){
				//cout << t << " " << s << endl;
				if(m[t][s]) return cout << "S",0;
			}
		}
	}
	cout << "N";
	return 0;
}