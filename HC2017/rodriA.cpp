#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
const double pi=acos(-1);
typedef pair<double,double>pt;
double val(pt a){
	return sqrt(a.x*a.x+a.y*a.y);
}
double pun(pt a , pt b){
	return a.x*b.x+a.y*b.y;
}
int main(){
	int test;
	cin>>test;
	int x,y,ANG;
	for(int te=1;te<=test;te++){		
		cin>>ANG>>x>>y;
		if(ANG==0){
			printf("Case #%d: white\n", te);
			continue;
		}
		x-=50;
		y-=50;
		pt p=pt(x,y);
		if(val(p)>50.0){
			printf("Case #%d: white\n", te);
			continue;
		}
		if(ANG>=60 and x>=0){
			printf("Case #%d: black\n", te);
			continue;
		}
		if(ANG<60 and x<0){
			printf("Case #%d: white\n", te);
			continue;
		}
		if(x<0){
			x=-x;
			y=-y;
		}
		//cout<<x<<" "<<y<<endl;
		
		pt q=pt(0.0,50.0);
		double a = acos(pun(p,q)/(val(p)*val(q)));
		
		double ang = ANG;
		ang=(ang/100.0)*2*pi;
		//cout<<a<<" "<<ang<<endl;
		if(a<=ang)printf("Case #%d: black\n", te);
		else printf("Case #%d: white\n", te); 
			
	}
	return 0;
}
