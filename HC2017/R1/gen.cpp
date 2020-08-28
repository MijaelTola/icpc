#include <iostream>
#include <cstdlib>

using namespace std;
int main(){
	for (int i = 0; i < 5000;){
		int a = random()%20+1;
		int b = random()%20+1;
		if(a != b){
			cout << a << " " << b << "\n";
			i++;
		}
	}
}
