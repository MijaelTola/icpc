#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a = 1;
	int b = 0;
	int c = 0;
	int p = 0;
	while(p < n){
		c = a + b;
		//cout << c << endl;
		a = b;
		b = c;
		p++;
	}
	cout << c << endl;
	return 0;
}
