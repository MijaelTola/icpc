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

struct point{
    double x,y;
    point(){}
    point(int _x,int _y){
        x = _x; y = _y;
    }
};

point operator +(const point &A, const point &B){return point(A.x+B.x,A.y+B.y);}
point operator -(const point &A, const point &B){return point(A.x-B.x,A.y-B.y);}
point operator *(const point &A, const point &B){return point(A.x*B.x,A.y*B.y);}

double cross(point A, point B){return A.x*B.y-A.y*B.x;}
double dot(point A, point B){return A.x*B.x+A.y*B.y;}
double distance(point A, point B){return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    point mid(50,50);
    point top(50,100);
    point start = top-mid;
    for (int k = 1; k <= t; ++k){
        int p,x,y; cin >> p >> x >> y;
        point P(x,y);
        cout << "Case #"<<k<<": ";
        double dist = distance(mid,P);
        if(dist > 50.0 or !p){
            cout << "white\n";
            continue;
        }
        point v1 = P-mid;
        double angle = 3.6*p;
        double areaT = (50.0*50.*angle)/2.0;
        double dott = dot(start,v1);
        double det = cross(v1,start);
        double angle2 = (atan2(det,dott)*180.0)/M_PI;   
        if(angle2 < 0) angle2+=360;
        double curArea = (50.0*50.0*angle2)/2.0;
        if(areaT >= curArea) cout << "black\n";
        else cout << "white\n";
    }
    return 0;
}

