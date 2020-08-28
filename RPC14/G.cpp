#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>
#include <string> 
#include <sstream>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;

long double dis(int x,int y, int a, int b){
	return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}
int main(){
	
	int ax,ay,bx,by,cx,cy;
	cin >> ax >> ay >>bx >> by >> cx >> cy;
	long double r; cin >> r;
	long double a = dis(ax,ay,bx,by);
	long double b = dis(ax,ay,cx,cy);
	long double c = dis(cx,cy,bx,by);
	
	long double area = sqrt(4*a*a*b*b-((a*a+b*b-c*c)*(a*a+b*b-c*c)))/4.0;
	
	long double radio = 2*area/(a+b+c);
	cout.precision(3);
	cout << fixed << (100-(long double)((radio*100.0)/r))*-1 << "\n";
	return 0;
}
