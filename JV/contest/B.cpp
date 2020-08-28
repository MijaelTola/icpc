#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

priority_queue<int> q;
int convert(string x){
	istringstream ss(x);
	int y;
	ss >> y;
	return y;
}
int main(){
	string x;
	getline(cin,x);
	bool sw = true;
	string num = "";
	int you;
	for (int i = 0; i < x.size(); ++i){
	//	cout << "ASDFASDFASDF" << endl;
		if(isdigit(x[i])) num += x[i];
		else{
	//		cout <<num << " ";
			int p = convert(num);
			num = "";
	//		cout << p << endl;
			if(sw){
				you = p;
				sw = false;
				continue;
			}	
			q.push(p);
		}		
	}
	if(num != "") {
		int p = convert(num);
		q.push(p);
	//	cout << p  << endl;
	}
	
	int ans = 0;
	
	while(you <= q.top()){
		you++;
		int a = q.top(); q.pop();
		a--;
		q.push(a);
		ans++;
	}
	cout << ans << endl;
	return 0;
}
