#include <bits/stdc++.h>

using namespace std;


int main() {
  
  long double r;
  cin >> r;
  
  long double a = 0, b = 100000;
  
  auto distance = [&](long double x, long double y, long double x2, long double y2) {
  	return sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
  };
  	
  auto intersect = [&](long double x, long double y, long double x2, long double y2) {
  		return distance(x,y,x2,y2) < 2 * r;
  };
  
  for (int i = 0; i < 100; ++i) {
    long double mid = (a + b) / 2;
  	if(intersect(0, mid, mid, 0)) a = mid;
    else b = mid;
  }
  
  long double d = b;
  a = 0, b = 100000;
  
  for (int i = 0; i < 100; ++i) {
    long double mid = (a + b) / 2;
   	if(intersect(mid, mid, 0, d) or intersect(mid, mid, d, 0)) a = mid;
    else b = mid;
  }
  
  long double ans = 2 * (b + r);
  
  printf("%.7Lf\n", ans * ans);

  return 0;
}
