#include <iostream>

using namespace std;

int main(){
	string x;
	while(cin >> x){
	int ans = 0;
	int sz = 0;
	bool flag = false;
	for (int i = 0; i < x.size(); ++i){
		if(x[i] == '.' or x[i] == 'P') {
			//cout << "ASDF" << endl;
			sz++;
			if(x[i] == 'P') flag = true;
		}else{
			if(flag) ans = max(ans,sz);
			sz = 0;
			flag = false;
		}
	}
	cout << ans << "\n";
	}
	return 0;
}
