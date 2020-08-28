#include <bits/stdc++.h>

using namespace std;


int main(){
	string x;
	
	while(cin >> x and x != "END"){
		if(x[0] == '-'){
			bool flag = false;
			for (int i = x.size() -1; i >= 1; --i){
				int d = x[i] - '0';
				if(d == 9) continue;
				if(!flag){d++;}
				x[i] = d +'0';
				flag = true;
			}
			if(flag) cout << x << endl;
			else{
				cout << -1;
				for (int i = 1; i < x.size(); ++i)
					cout << x[i];
					cout << endl;
			}
			continue;
		}else{
	bool flag = false;
	bool carajo = false;
	string ans = x;
	string hola = x;
	for (int i = x.size()-1; i >= 1; --i){
		int d = x[i] - '0';
		int p = x[i-1] - '0';
		if(d < 8 and p > 0 and !flag){
			d+=2; p--;
			x[i] = char(d+'0');
			x[i-1] = char(p+'0');
			flag = true;
		}
		if(x[i-1] == '0') carajo = true; 
	}
	if(flag){
		bool sw = false;
		for (int i = 0; i < x.size(); ++i){
			if(!sw and x[i] == '0') continue;
			sw = true;
			cout << x[i];
		}
		cout << endl;
	} else{
		for (int i = ans.size()-1; i >= 0; --i){
			int d = ans[i] - '0';
			if(d == 9) continue;
			d++;
			ans[i] = char(d+'0');
			flag = true;
			break; 
		}
		if(flag)cout<< "-" << ans << endl;
		else cout  << -1 << ans << endl;
	}
}
}
}
