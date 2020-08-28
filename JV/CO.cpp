#include <bits/stdc++.h>

using namespace std;

int parents[100020];
int r[100020];
int ans;
int find(int x){
	if(x == parents[x]) return x;
	else return parents[x] = find(parents[x]);
}
bool sameC(int x, int y){
	if(find(x) == find(y)) return true;
	else return false;
}
void makeset(int n){
	for (int i = 0; i <= n; ++i){
		parents[i] = i;
		r[i] = 0;
	}
		
}
void Union(int x, int y){
	int px = find(x);
	int py = find(y);
	if(r[px] > r[py]){
		parents[py] = px;
	}else{
		parents[px] = py;
		if(r[px] == r[py]){
			 r[py]++;
		}
	}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n,c;
	scanf("%d %d", &n,&c);
	ans = n;
	makeset(n);
	for (int i = 0; i < c; ++i)
	{
		int a,b,x;
		scanf("%d %d %d", &a,&b,&x);
		if(x == 1){
			if(!sameC(a,b)){
				Union(a,b);
				ans--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}