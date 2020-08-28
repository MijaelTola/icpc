#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct grid{
	int x,y,time,price;
	grid(){}
	grid(int _x, int _y,int _time, int _price){
		x = _x;
		y = _y;
		time = _time;
		price = _price;
	}
	bool operator < (const grid &g){
		return time < g.time;
	}
};

int n,m,p,xc,yc;
int dp[510];

vector<grid> v;
int manhattan(int pos,int x, int y){
	return abs(v[pos].x-x)+ abs(v[pos].y-y);
}

int f(int pos,int time, int x,int y){
	
	if(pos == (int)v.size()) return 0;
	
	if(dp[pos] != -1) return dp[pos];
	int distance = manhattan(pos,x,y);
	int addtime = v[pos].time - time;
	int ans = -1;
	if(distance+time <= v[pos].time)
		ans = max(ans,f(pos+1,addtime+time,v[pos].x,v[pos].y)+v[pos].price);
	ans = max(ans,f(pos+1,time,x,y));
	return dp[pos] = ans;
}
bool cmp(const grid a, const grid b){
	return a.time<b.time;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	
	while(t--){
		memset(dp,-1,sizeof dp);
		v.clear();
		cin >> n >> m >> p >> xc >> yc;
		for (int i = 0; i < n; ++i){
			int x,y,time,price;
			cin >> x >> y >> time >> price;
			v.push_back(grid(x,y,time,price));
		}
		sort(v.begin(),v.end(),cmp);
		cout << f(0,0,xc,yc) << "\n";
	}
	return 0;
}
