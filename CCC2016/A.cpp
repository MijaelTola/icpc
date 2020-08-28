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
    int type;
    int ans;
    int r,b;
    bool fijo;
    point(double x,int y,double type,int ans, bool fijo):x(x),y(y),type(type),ans(ans),fijo(fijo){r = b = 0;};
};

bool cmp(const point &A, const point &B){
    if(A.x == B.x) return A.y >  B.y;
    return A.x < B.x;
}
vector<point> v;
//vector<point> f;
//vector<point> w;
double k;
double distance(point &A, point &B){
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}


int ans[1000000];
//int ans2[1000000];
/*STRESSTEST*/
/*int solve(point &A){
    int r = 0, b= 0;
    for (int i = 0; i < (int)f.size(); ++i){
 //       cout << f[i].x << " " << f[i].y << " " << (double)distance(A,f[i]) << " " << f[i].type << endl;
        if(distance(A,f[i]) <= k){
            if(f[i].type) r++;
            else b++;
        }
    }
    //cout << r << " " << b << endl;
    if(r > b) return true;
    if(b > r) return false;
    return -1;
}*/

int main(){
    int n,m;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i){
        double x,y; cin >> x >> y;
        v.push_back(point(x,y,false,-1,true));//blue
    }
    for (int i = 0; i < m; ++i){
        double x,y; cin >> x >> y;
        v.push_back(point(x,y,true,-1,true));//red
    }
    int q; cin >> q;

    for (int i = 0; i < q; ++i){
        double x,y; cin >> x >> y;
        point A(x,y,-1,i,false);
        v.push_back(A);
    }
    sort(v.begin(),v.end(),cmp);
    for (int i = 0; i < (int)v.size(); ++i){
        if(v[i].type == -1){
            int dx = v[i].x-k;
            int pos = i-1;
            if(pos < 0)continue;
            while(v[pos].x >= dx and pos >= 0){
                if(distance(v[pos],v[i]) and distance(v[pos],v[i]) <= k and v[pos].ans < v[i].ans and v[pos].fijo){
                    if(v[pos].type) v[i].r++;
                    else if(v[pos].type == 0) v[i].b++;
                }
                pos--;
            }
        }
    }
    for (int i = v.size()-1; i >= 0; --i){
        if(v[i].type == -1){
            int dx = v[i].x+k;
            int pos = i+1;
            if(i+1 > (int)v.size()) continue;
            while(v[pos].x <= dx and pos < (int)v.size()){
                if(distance(v[pos],v[i]) > 0 and distance(v[pos],v[i])<=k and v[pos].fijo){
                    if(v[pos].type)v[i].r++;
                    else if(v[pos].type == 0) v[i].b++;
                }
                pos++;
            }
            if(v[i].r > v[i].b) ans[v[i].ans] = 1;
            else if(v[i].r < v[i].b) ans[v[i].ans] = 0;
            else ans[v[i].ans] = -1;
        }
    }
    for (int i = 0; i < q; ++i)
        cout << ans[i] << "\n";
    return 0;
}
