#include <bits/stdc++.h>

using namespace std;

#define Vector Point
#define PP double

const double EPS = 1e-8;
struct Point{
    PP x,y;
    Point(){}
    Point(PP xx,PP yy){x = xx;y = yy;}
    void p(){cout << "::> " << x << " " << y << endl;}
};

Point operator + (const Point &A,const Point &B){return Point(A.x+B.x,A.y+B.y);}
Point operator - (const Point &A,const Point &B){return Point(A.x-B.x,A.y-B.y);}
Point operator * (const Point &A,const Point &B){return Point(A.x*B.x,A.y*B.y);}
Point operator / (const Point &A,double k){return Point(A.x/k,A.y/k);}
Point operator * (const Point &A,double k){return Point(A.x*k,A.y*k);}
bool  operator < (const Point &A,const Point &B){return pair<PP,PP>(A.x,A.y) < pair<PP,PP>(B.x,B.y);}

double cross(Point A,Point B){return A.x*B.y - A.y*B.x;}
double dist(Point A,Point B){return hypot(A.x - B.x,A.y-B.y);}
double area2(Point A,Point B,Point C){return cross(B-A,C-A);}//For the triangle A,B,C  using A->B, A->C
double area(Point A,Point B,Point C){return cross(B-A,C-A);}//For the triangle A,B,C  using A->B, A->C

bool pointInBox(Point P,Point A,Point B){//Point P inside box A,B
    return P.x >= min(A.x,B.x) and P.x <= max(A.x,B.x) and
        P.y >= min(A.y,B.y) and P.y <= max(A.y,B.y);
}

bool pointOverSegment(Point P,Point A,Point B){//p over AB
    return fabs(area2(A,B,P)) <= EPS and pointInBox(P,A,B);
}

bool pointInPoly(vector<Point> pol,Point p){
    int cont=0,len=pol.size();
    Point act,sig;

    for(int i=0;i<len;i++){
        if (pointOverSegment(p,pol[i],pol[(i+1)%len]))return true; // to include point overSegment uncomment it
        act = pol[i] - p;
        sig = pol[(i+1)%len] - p;//focus on this :v
        if (act.y>sig.y)
            swap(act,sig);
        if (act.y<0 and sig.y>=0 and cross(sig,act)>=0)
            cont++;
    }
    return cont%2==1;
}

bool segmentsIntersect(Point A,Point B,Point C,Point D){//AB, CD
   double A1 = area2(C, D, A);
   double A2 = area2(C, D, B);
   double A3 = area2(A, B, C);
   double A4 = area2(A, B, D);

   if( ((A1 > 0 and A2 < 0) or (A1 < 0 and A2 > 0)) and
       ((A3 > 0 and A4 < 0) or (A3 < 0 and A4 > 0)))
           return true;

   else if(A1 == 0 and pointOverSegment(A, C, D)) return true;
   else if(A2 == 0 and pointOverSegment(B, C, D)) return true;
   else if(A3 == 0 and pointOverSegment(C, A, B)) return true;
   else if(A4 == 0 and pointOverSegment(D, A, B)) return true;
   else return false;
}

vector <Point> ConvexHull(vector <Point> P) {
    sort(P.begin(),P.end());
    int n = P.size(),k = 0;
    Point H[2 * n];
    
    for(int i=0;i<n;++i){
        while(k>=2 && area(H[k-2],H[k-1],P[i]) <= 0) --k;
        H[k++] = P[i];
    }
    
    for(int i=n-2,t=k;i>=0;--i){
        while(k>t && area(H[k-2],H[k-1],P[i]) <= 0) --k;
        H[k++] = P[i];
    }
    
    return vector <Point> (H,H+k-1);
}

int main () {

    int t;
    cin >> t;
    while(t--) {
        vector<Point> pol;
        Point p1,p2, p3;

        for (int i = 0; i < 2; ++i) {
            int x,y;
            cin >> x >> y;
            pol.push_back(Point(x,y));
        }
 
        int x,y,a,b,c,d;
        cin >> x >> y >> a >> b >> c >> d;

        p1 = Point(x,y);
        p2 = Point(a,b);
        p3 = Point(c,d);

        pol.push_back((p3 * 1e9) + pol[0]);
        pol.push_back((p3 * 1e9) + pol[1]);

        bool f3 = 0;
        f3 |= segmentsIntersect(pol[0],pol[1], p1, p2);
        f3 |= segmentsIntersect(pol[0],pol[2], p1, p2);
        f3 |= segmentsIntersect(pol[1],pol[3], p1, p2);

        pol = ConvexHull(pol);

        bool f1 = pointInPoly(pol,p1);
        bool f2 = pointInPoly(pol, p2);
        if(!f1 and !f2 and !f3) {
            cout << "No\n";
        } else  cout << "Yes\n";
    }

    return 0;
}
