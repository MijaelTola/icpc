#include <iostream>

using namespace std;

int v[1000010];
int main(){
	int n,x;
	while(scanf("%d",&n) and n){
	for (int i = 0; i < n; ++i) scanf("%d",&v[i]);
	int ans = 0;
	int id1 = -1;
	int id2 = -1;
	int sum = 0;
	int last = 1;
	for (int i = 0; i < n; ++i){
		sum+=v[i];
		if(sum > ans){
			id1 = last;
			id2 = i;
			ans = sum;
		}
		if(sum < 0) 
		{
		last = i+1; sum = 0;
		}
	}
	cout << ans <<" " << id1 << " " << id2<< endl;
}
	return 0;
}
