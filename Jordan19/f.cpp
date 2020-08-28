#include <bits/stdc++.h>

using namespace std;

#define Vector Point

const double pi = acos(-1);

int input () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

int n;
struct Point {
    double x,y;
    double a,r;
    Point() {}
    Point(double _, double __) {
        x = _, y = __;
    }
    double mod()  { return sqrt(x*x + y*y); }
};

Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }

double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; }

double findAngle(Vector A, Vector B) {
    double rad = acos(dot(B, A)/ (A.mod() * B.mod()));
    return rad * 180 / pi;
}


bool ver(const Point &A, const Point &B) {
    Point C = Point(10000, A.y);
    double angle = findAngle(B - A, C - A);
    if(B.y < A.y) angle = 360 - angle; 
    return A.a - A.r <= angle and angle <= A.a + A.r;
}

vector<int> G[3010];
int vis[3010];
int in[3010];

bool dfs(int u) {
    if(vis[u] == 2) return 0;
    if(vis[u] == 1) return 1;
    vis[u] = 1;
    int ans = 0;
    for (int v: G[u]) ans |= dfs(v);
    vis[u] = 2;
    return ans;
}

int main() {

    n = input();
    vector<Point> v;

    for (int i = 0; i < n; ++i) {
        Point p;
        int x,y,a,r;
        x = input();
        y = input();
        a = input();
        r = input();
        p.x = x, p.y = y, p.a = a, p.r = r;
        v.push_back(p);
    }


    for (int i = 0; i < n; ++i ) 
        for (int j = i + 1; j < n; ++j) {
            if(i == j) continue;
            if(ver(v[i], v[j])) {
                in[j]++;
                G[i].push_back(j);
            }
            if(ver(v[j], v[i])) {
                in[i]++;
                G[j].push_back(i);
            }
        }

    bool as = 0;

    for (int i = 0; i < n; ++i) 
        if(!vis[i]) as |= dfs(i);

    if(as) return printf("-1\n"), 0;

    queue<int> can;

    for (int i = 0; i < n; ++i)
        if(in[i] == 0) can.push(i);

    while(!can.empty()) {
        int x = can.front();
        can.pop();
        printf("%d ", x + 1);
        for (int u: G[x]) {
            in[u]--;
            if(in[u] == 0) can.push(u);
        }
    }

    printf("\n");
    return 0;
}

