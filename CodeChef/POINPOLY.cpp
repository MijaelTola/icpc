#include <bits/stdc++.h>
 
using namespace std;
 
const long double EPS = 1e-18;
struct Point {
    long double x, y;
    Point() {}
    Point(long double _, long double __) {
        x = _; y = __;
    }
};
 
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
long double cross(const Point &A, const Point &B) { return A.x * B.y - A.y * B.x; }
long double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }
bool operator <(const Point &a, const Point &b){
    if(abs(a.x - b.x) > EPS) return a.x < b.x;
    return a.y + EPS < b.y;
}
 
 
bool isInConvex(vector <Point> &A, const Point &P) {
    int n = A.size(), lo = 1, hi = A.size() - 1;
    if(area(A[0], A[1], P) <= 0) return 0;
    if(area(A[n-1], A[0], P) <= 0) return 0;
 
    while(hi - lo > 1) {
        int mid = (lo + hi) / 2;
        if(area(A[0], A[mid], P) > 0) lo = mid;
        else hi = mid;
    }
    
    return area(A[lo], A[hi], P) > 0;
}
 
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
 
int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {1,1,0,-1,-1,-1,0,1};
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        vector<Point> poly;
        vector<Point> ans;
        map<Point, bool> vis;
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            long double x,y;cin >> x >> y;
            poly.push_back(Point(x,y));
        }
        poly = ConvexHull(poly);
        int needed = n / 10;
        
        for (int i = 0; i < (int)poly.size(); ++i) {
            for (int j = 0; j < 8; ++j) {
                long double x = poly[i].x + dx[j];
                long double y = poly[i].y + dy[j];
                if(abs(x) <= 1e9 and abs(y) <= 1e9 
                        and isInConvex(poly, Point(x,y))
                        and vis[Point(x,y)] == 0
                        and (int)ans.size() < needed) {
                    vis[Point(x,y)] = 1;
                    ans.push_back(Point(x,y));
                }
            }
        }
        if((int)ans.size() == needed) {
            for (Point P: ans) cout << P.x << " " << P.y << "\n";
        }else cout << "-1\n";
 
    }
    return 0;
}
