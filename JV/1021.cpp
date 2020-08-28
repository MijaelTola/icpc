#include <bits/stdc++.h>

using namespace std;

int main(){

	long long x,y;

	while(cin >> x >> y){

	while(x != y){
		if(x > y)x /= 2;
		else y /= 2;
	}

	cout << x << endl;
}
	return 0;
}