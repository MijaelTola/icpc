#include <bits/stdc++.h>

using namespace std;

struct point{
    int x,y;
    point(){}
    point(int _, int __){
        x = _;
        y = __;
    }
};
point operator +(const point &a, const point &b) { return point(a.x + b.x, a.y + b.y); }
point operator -(const point &a, const point &b) { return point(a.x - b.x, a.y - b.y); }
point operator /(const point &a, double k) { return point(a.x/k, a.y/k); }
point operator *(const point &a, double k) { return point(a.x*k, a.y*k); }

double cross(const point &A, const point &B) { return A.x * B.y - A.y * B.x; }

point intersection(const point &A, const point &B, const point &C, const point &D){
    return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C));
}


int distance(int x1,int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
vector<point> p[1010];
map<pair<int,int>, int > mp;
int main(){
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int x,y,d; cin >> x >> y >> d;
        for (int j = 0; j < 4; ++j){
            int u = dx[j] * d + x;
            int v = dy[j] * d + y;
            point dp = point(u,v);
            p[i].push_back(dp);
        }
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            for (int k = 1; k < 5; ++k){
                for (int l = 1; l < 5; ++l){
                    point p1 = p[i][k % 5];
                    point p2 = p[i][(k - 1) % 5];
                
                    point d1 = p[i][l % 5];
                    point d2 = p[i][(l - 1) % 5];
                    
                    point cur = intersection(p1,p2,d1,d2);
                    
                    cout << "seg 1" << " " << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << "\n";
                    cout << "seg 2" << " " << d1.x << " " << d1.y << " " << d2.x << " " << d2.y << "\n";
                    cout << "seg 3" << " " << cur.x << " " << cur.y << " " << cur.x << " " << cur.y << "\n";
                    mp[make_pair(cur.x,cur.y)]++;
                }
            }
        }
    }
    
    /*int ans = 0;
    int x,y;
    for (pair<pair<int,int>,int> cur: mp){
        if(cur.second == n){
            ans++;
            x = cur.first.first;
            y = cur.first.second;
            cout << x << " " << y << " " << "\n";
        }
    }

    if(ans == 1) cout << x <<  " " << y << "\n";
    else if(ans > 1) cout << "uncertain\n";
    else cout << "impossible\n";*/
    return 0;
}

