#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1);
const double EPS = 1e-3;

struct Point {
    double x,y;
    Point() {}
    Point(double _, double __) {
        x = _, y = __;
    }
};

Point operator - (const Point &A, const Point &B){
    return Point(A.x-B.x,A.y-B.y);
}

double cross(Point A,Point B){return A.x*B.y - A.y*B.x;}

double area2(Point A,Point B,Point C){return cross(B-A,C-A);}

bool pointInBox(Point &P,Point &A,Point &B){
    return P.x >= min(A.x,B.x) and P.x <= max(A.x,B.x) and
        P.y >= min(A.y,B.y) and P.y <= max(A.y,B.y);
}

bool pointOverSegment(Point &P,Point &A,Point &B){//p over AB
    return fabs(area2(A,B,P)) <= EPS and pointInBox(P,A,B);
}

bool pointInPoly(vector<Point> &pol,Point &p){
    int cont = 0, len = pol.size();
    Point act,sig;
    for(int i = 0;i < len; i++){
        if (pointOverSegment(p,pol[i],pol[(i+1)%len]))return 1; 
        act = pol[i] - p;
        sig = pol[(i + 1)%len] - p;//focus on this :v
        if (act.y > sig.y)
            swap(act,sig);
        if (act.y<0 and sig.y>=0 and cross(sig,act)>=0)
            cont++;
    }
    return cont%2==1;
}


int n,m,z;
vector<Point> points;
vector<Point> pol;
Point rotate(Point &a, double angle) {
    double rad = angle * pi / 180;
    double x = a.x * cos(rad) - a.y * sin(rad);
    double y = a.y * cos(rad) + a.x * sin(rad);
    return Point(x,y);
}
int main() {
    
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d",&n,&m,&z);

        for (int i = 0; i < n; ++i) {
            int x,y;
            scanf("%d%d",&x,&y);
            points.push_back(Point(x,y));
        }

        double mid = z / 2.0;

        pol.push_back(Point(mid,0));
        pol.push_back(Point(-mid,100000));
        pol.push_back(Point(mid,100000));
        pol.push_back(Point(-mid,0));
        
        bool flag = 0;
        for (int i = 0; i <= 360; ++i) {
            vector<Point> p;
            for (int j = 0; j < 4; ++j) 
                p.push_back(rotate(pol[j],i));
            
            int cnt = 0;
            for (int j = 0; j < (int) points.size(); ++j) 
                cnt += pointInPoly(p, points[j]);

            if(cnt >= m) {
                flag = 1;
                break;
            }
        }
        if(!flag) puts("No");
        else puts("Yes");
    }
    return 0;
}
