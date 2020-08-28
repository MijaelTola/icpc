#include <iostream>

using namespace std;


int main(){
	int t; cin >> t;
	
	while(t--){
		int n; cin >> n;
		string x; cin >> x;
		int count = 0;
		int ans = 0;
		for (int i = 0;i < x.size();++i){
			aif(count >= i){
				int p = x[i]-'0';
				count += p;
			}else{
			//	cout << i << " " << count << endl;
				int d = i - count;
				ans += d;
				count += d;
				int p = x[i]-'0';
				count += p;
			} 
		}
		cout << ans << "\n";
	}
	return 0;
}
