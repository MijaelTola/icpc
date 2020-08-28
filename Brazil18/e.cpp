#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	string texto,patron;
	cin>>texto>>patron;
	int ans = 0;
	for(int i = 0; i < texto.size() - patron.size() + 1; i++){
		bool sw = true;
		for(int j = 0; j < patron.size(); j++){
			if(patron[j] == texto[j + i])
				sw = false;
		}
		if(sw){
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
