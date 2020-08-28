#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int,int> > k;

bool cmp(pair<int,int> a, pair<int,int> b){
	return (double)a.first/a.second > (double)b.first/b.second;
}
int main(){
	int n,c; cin >> n >> c;
	for (int i = 0; i < n; ++i){
		int v,w; cin >> v >> w;
		k.push_back({v,w});
	}
	sort(k.begin(),k.end(),cmp);
	double ans = 0;
	for (int i = 0; i < n; ++i){
		if(c == 0) break;
		int a = min(k[i].second,c);
		ans += a*((double)k[i].first/k[i].second);
		c-=a;
	}
	cout.precision(4);
	cout << fixed <<ans << "\n";
	return 0;
}
