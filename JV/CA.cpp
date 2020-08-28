#include <bits/stdc++.h>

using namespace std;

int main(){
	stack<char> s;
	int n;
	cin >> n;
	cin.ignore();
	while(n--){
		string x;
		bool sw = false;
		getline(cin,x);
		for (int i = 0; i < x.size(); ++i)
		{
			if(x[i] == '(' or x[i] == '[') s.push(x[i]);
			else{
				if(s.empty()){
					//cout << "No";
					sw = true; break;
					
				} 
				if(x[i] == ')'){
					if(s.top() == '(') s.pop();
					else{
						sw = true; break;
					}
				}
				if(x[i] == ']'){
					if(s.top() == '[') s.pop();
					else{
						sw = true; break;
					}
				}

			}
		}
		if(sw)  cout << "No";
		else if(!s.empty()) cout << "No";
		else cout <<"Yes";
		cout << endl;
		while(!s.empty()) s.pop();
	}

	return 0;
}