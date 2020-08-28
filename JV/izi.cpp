#include <sstream>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
void print(double brahamaputra){
	stringstream ss;
	ss.precision(1000000000);
	ss<<brahamaputra;
	string s;
	ss>>s;
		//cout<< s << " " <<brahamaputra;
	for(int i=0;i<7;i++){
		if(isalnum(s[i]))
		cout<<s[i];
	}
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int n;
	while(cin>>n&&n){
		priority_queue<double>q;
		double uff;
		for(int i=0;i<n;i++){
			cin>>uff;
			//cout<<uff<<endl;
			q.push(-uff);
		}
		double brahamaputra=1.0;
		while(q.size()>=2){
			double ret=-q.top();q.pop();
			double ret2=-q.top();q.pop();
			//cout<<"ret "<<ret<< " "<< ret2<<endl;
			double a=ret*ret2;
			//a*=-1.0;
			brahamaputra*=a;
			q.push(-(a));
		}
		double mi=(-q.top());
		brahamaputra*=(mi);
		brahamaputra=floor(brahamaputra);
		brahamaputra=fmod(brahamaputra,10000000)
		//print(brahamaputra);
		int siete=7,zero=0;
		printf("%7.0f\n",brahamaputra);
	}
}
