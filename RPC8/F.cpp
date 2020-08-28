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

using namespace std;

typedef long long ll;

int x,y,d;

void gcd(int a,int b){
    if(b == 0) {x = 1; y = 0; d = a; return;}
    gcd(b,a%b);
    int x1 = y;
    int y1 = x - (a/b)*y;
    x = x1;
    y = y1;
}
int main(){
    cin >> x >> y >> d;
    int g = __gcd(x,y);
    x/=g;
    y/=g;
    d/=g;
    gcd(x,y);
    x*=d;
    y*=d;
    cout << x << " " << y << endl;
    return 0;
}
