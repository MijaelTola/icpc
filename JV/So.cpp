#include <iostream>
#include <queue>

using namespace std;
priority_queue<int> q;
int main(){
	int t; cin>> t;
	while(t--){
		while(!q.empty()) q.pop();
		int n; cin >> n;
		for(int i = 0; i < n; ++i){
			char c; int x;
			cin >> c;
			if(c == 'I'){
				cin >> x;
				q.push(-x);
			} 
			else{
				cout << -q.top() << " ";
				q.pop();
			}
		}
		cout << "\n";
	}
}
