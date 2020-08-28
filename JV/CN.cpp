#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,x,y,r;
	int t;
	scanf("%d",&t);
	while(t--){
	scanf("%d %d %d %d",&n,&x,&y,&r);
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int x1,y1;
		scanf("%d %d",&x1,&y1);
		int dx = x1-x;
		int dy = y1-y;
		int dist = sqrt(dx*dx+dy*dy);
		if(dist < r) ans++;
	}
	cout << ans << endl;
	}
	return 0;
}