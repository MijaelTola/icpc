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

struct point{
    double x,y;
    point(double x,double y): x(x), y(y){}
};

bool cmp(const point &A, const point &B){
    if(A.x == B.x) return A.y > B.y;
    return A.x < B.x;
}

vector<point> r;
vector<point> b;
int n,m;
double k;

int bs(point &X, bool flag){
    if(!flag){
        int a = -1; int br = r.size();
        while(br-a>1){
            int mid = (a+br)>>1;
            if(r[mid].x >= X.x) br = mid;
            else a = mid;
        }
        return br;
    }
    int a = -1; int br = b.size();
    while(br-a>1){
        int mid = (a+br)>>1;
        if(b[mid].x >= X.x) br = mid;
        else a = mid;
    }
    return br;
}
double distance(point &A, point &B){
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

int brute(point &X){
    int re = 0;
    for (int i = 0; i < (int)r.size(); ++i){
        double d = distance(X,r[i]);
        if(d > 0 and d <= k) re++;
    }
    int bu = 0;
    for (int i = 0; i < (int)b.size(); ++i){
        double d = distance(X,b[i]);
        if(d > 0 and d <= k) bu++;
    }
    if(bu > re) return 0;
    if(re > bu) return 1;
    return -1;
}
int solve(point &X){
    int posr = bs(X,false);
    int pos = posr;
    int dx = X.x+k;
    int red = 0;
    while(r[pos].x <= dx and pos < (int)r.size()){
        double dis = distance(r[pos],X);
        if(dis>0 and dis <= k) red++;
        pos++;
    }
    pos = posr-1;
    dx = X.x-k;
    while(r[pos].x >= dx and pos >= 0){
        double dis = distance(r[pos],X);
       // cout << r[pos].x << " " << r[pos].y << " " << dis << endl;
        if(dis>0 and dis <= k) red++;
        pos--;
    }
    int posb = bs(X,true);
    int blue = 0;
    pos = posb;
    dx = X.x+k;
    while(b[pos].x <= dx and pos < (int)b.size()){
        double dis = distance(b[pos],X);
       // cout << b[pos].x << " " << b[pos].y << " " << dis << endl;
        if(dis > 0 and dis <= k) blue++;
        pos++;
    }
    pos = posb-1;
    dx = X.x-k;
    while(b[pos].x >= dx and pos >= 0){
        double dis = distance(b[pos],X);
       // cout << b[pos].x << " " << b[pos].y << " " << dis << endl;
        if(dis > 0 and dis <= k) blue++;
        pos--;
    }
   // cout << blue << " " << red  << " totalA"<<endl;
    if(blue > red) return 0;
    if(red > blue) return 1;
    return -1;   
}

int main(){
    ios::sync_with_stdio(false); cin.tie();
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i){
        double x,y; cin >> x >> y;
        b.push_back(point(x,y));
    }
    for (int i = 0; i < m; ++i){
        double x,y; cin >> x >> y;
        r.push_back(point(x,y));
    }
   // cout << b.size() <<  " " << r.size() << endl;
    sort(b.begin(),b.end(),cmp);
    sort(r.begin(),r.end(),cmp);
    
    //for (int i = 0; i < (int)r.size(); ++i) cout << r[i].x << " "; cout << endl;
    //for (int i = 0; i < (int)b.size(); ++i) cout << b[i].x << " "; cout << endl;
    int q; cin >> q;
    while(q--){
        double x,y; cin >> x >> y;
        point X(x,y);
        int ans1 = solve(X);
 //       int ans2 = brute(X);
          cout << ans1 << "\n";
    }
    return 0;
}

