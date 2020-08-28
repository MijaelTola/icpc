#include <iostream>
#include <queue>

using namespace std;
priority_queue<int> q;
int main(){
	
	int n;
	while(cin >> n){
		for (int i = 0; i < n; ++i){
			int x; cin >> x;
			q.push(-x);
		}
		
		int ans = -1;
		
		while(!q.empty()){
			int u = -q.top();
			int a = q.size();
			ans = max(ans,u*a);
			q.pop();
		}
		cout << ans << endl;
	}
	return 0;
}
