#include <iostream>
#include <cstring>

using namespace std;

int v[100];
int n;
int home;

int f(int pos,int left,int cantidad){
	if(left == 0) return 0;
	int ans = 1e9;
	if(cantidad == 0)
		return f(home,left,5)+abs(v[pos]-v[home]);
	else{
		for (int i = 0; i < n; ++i)
			ans = min(ans,f(i,left-1,cantidad-1)+abs(v[pos]-v[i])+1);
	//	ans = min(ans,f(home,left,5) + abs(v[pos]-v[home]));
	}
	return ans;
}
int main(){
	cin >> n;

	for (int i = 0; i <= n; ++i) cin >> v[i];
	
	home = n;
	
	cout <<f(home,n,5) << endl;
	return 0;
}
