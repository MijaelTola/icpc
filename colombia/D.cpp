#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-8
#define PI acos(-1)
#define Vector Point

struct Point {
    long long x, y;
    int idx;
    Point(){}
    Point(long long a, long long b) { x = a; y = b;}
    double mod2() { return x*x + y*y; }
    double mod()  { return sqrt(x*x + y*y); }
    double arg()  { return atan2(y, x); }
    Point ort()   { return Point(-y, x); }
    Point unit()  { double k = mod(); return Point(x/k, y/k); }
};

Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator /(const Point &a, double k) { return Point(a.x/k, a.y/k); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }

bool operator ==(const Point &a, const Point &b) {
    return abs(a.x - b.x) < EPS && abs(a.y - b.y) < EPS;
}
bool operator !=(const Point &a, const Point &b) {
    return !(a==b);
}
bool operator <(const Point &a, const Point &b) {
    if(abs(a.x - b.x) > EPS) return a.x < b.x;
    return a.y + EPS < b.y;
}


double dist(const Point &A, const Point &B)    { return hypot(A.x - B.x, A.y - B.y); }
long long cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; }
long long area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

vector <Point> ConvexHull(vector <Point> P) {
    sort(P.begin(),P.end());
    int n = P.size(),k = 0;
    Point H[2*n];
    
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

vector<Point> pol;
long long ac[300010];
int pos[300010]; 

double area(const vector <Point> &P){
    int n = P.size();
    long long A = 0;
    for(int i=1; i<=n-2; i++) {
        A += area(P[0], P[i], P[i+1]);
        ac[i + 1] = A;
    }
    return abs(A/2);
}

int main() {
	int n,m;
	cin >> n >> m;
	
	for (int i = 0; i < n; ++i) {
		int x,y; cin >> x >> y;
        Point p = Point(x,y);
        p.idx = i;
		pol.push_back(p);
	}	

    
	pol = ConvexHull(pol);
    
    for (int i = 0; i < n; ++i) {
        int id = pol[i].idx;
        pos[id] = i;
    }
    area(pol);
    long long ans = 0;
    while(m--) {
        int x,y;
        cin >> x >> y;
        x--,y--;
        x = pos[x], y = pos[y];
        if(y < x) swap(x,y);
        long long a = abs(ac[y]);
        long long b = abs(ac[x]);
        a -= b;
        Point t1 = pol[x] - pol[0];
        Point t2 = pol[y] - pol[0];
        long long ar = abs(cross(pol[x] - pol[0], pol[y] - pol[0]));
        long long cur = a - ar;
        long long left = abs(ac[n - 1]) - cur;
        cur = min(cur,left);
        ans = max(ans,cur);
    }
    cout.precision(10);
    cout << fixed << (double)ans / 2.0 << "\n";
    return 0;
}
