#include <bits/stdc++.h>

using namespace std;

int parents[200100];
vector<int>dx[200100];
vector<int>dy[200100];	
int find(int x){
	if(x == parents[x]) return x;
	else return parents[x] = find(parents[x]);
}
bool sameC(int x, int y){
	if(find(x) == find(y)) return true;
	else return false;
}
void makeset(int n){
	for (int i = 0; i <= n; ++i)
		parents[i] = i;	
}
void Union(int x, int y){
	int px = find(x);
	int py = find(y);
	parents[px] = py;
}
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x,y; cin >> x >> y;
		dx[x].push_back(i);
		dy[y].push_back(i);
	}
	makeset(200010);
	int sz = n;
	for (int i = 0; i <= 200010; ++i)
	{
		for (int j = 1; j < dx[i].size(); ++j)
		{
			int u = dx[i][j]; int v = dx[i][j-1];
			if(!sameC(u,v)){
				sz--; Union(u,v);
			}
		}
		for (int j = 1; j < dy[i].size(); ++j)
		{
			int u = dy[i][j]; int v = dy[i][j-1];
			if(!sameC(u,v)){
				sz--; Union(u,v);
			}
		}
	}
	//	cout << sz << endl;
	int m; cin >> m;
	double ans = sz;
	for (int i = 0; i < m; ++i)
	{
		int x,y;
		cin >> x >> y;
		bool sw = false;
		if(dx[x].size() and !sameC(n+i,dx[x][0])){
			sw = true;
			Union(n+i,dx[x][0]);
		}
		if(dy[y].size() and !sameC(n+i,dy[y][0])){
			Union(n+i,dy[y][0]);
			if(sw) sz--;
			sw = true;
		}
		if(!sw) sz++;
		ans += sz;
		dx[x].push_back(n+i);
		dy[y].push_back(n+i);
	//	cout << sz << " asdfasdf"  << endl;
	}
	double d = m+1.0;
	//cout << ans << " " << d << endl;
	cout.precision(2);
	cout << fixed  << ans/d;
	return 0;
}