#include <iostream>
#include <queue>
using namespace std;

queue<char> q;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	string x;
	while(cin >> x){
		bool sw = true;
		while(sw){
			sw = false;
			for (int i = 0; i < x.size(); ++i){
				if(x[i] == x[i+1]){
					string a = x.substr(0,i);
					string b = x.substr(i+2,x.size());
					x = a+b ;
					sw = true; 
					break;
				}
			}
		}
		if(x.size() == 0) cout << "Posible\n";
		else cout <<"Imposible\n";
	}	
	return 0;
}
