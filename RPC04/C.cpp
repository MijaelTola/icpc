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

pair<int,int> A[500010];
int a[500010];
int b[500010];

long double dist(long long x, long long y, long long x1, long long y1){
    return sqrtl((x-x1)*(x-x1)+(y-y1)*(y-y1));
}
int main(){
    int n;
    scanf("%d",&n); n += 2;

    for (int i = 0; i < n; ++i)
        scanf("%d %d",&A[i].first, &A[i].second);

    for (int i = 1; i < n-1; ++i){
        int cur = i-1;
        while(cur > 0 and A[i].second >= A[cur].second) cur = a[cur];
        a[i] = cur;
    }

    for (int i = n-2; i >= 1; --i){
        int cur = i+1;
        while(cur < n-1 and A[i].second >= A[cur].second) cur = b[cur];
        b[i] = cur;
    }

    for (int i = 1; i < n-1; ++i){
        int L = a[i];
        int R = b[i];
        int Lx = A[L].first; int Ly = A[L].second;
        int Rx = A[R].first; int Ry = A[R].second;
        int curx = A[i].first; int cury = A[i].second;
        long double dL = dist(Lx,Ly,curx,cury);
        long double dR = dist(Rx,Ry,curx,cury);
        printf("%d %d %0.4Lf %0.4Lf\n",L,R,dL,dR);
    }
    return 0;
}
/*
   0 5 2.8284 8.2462
   1 4 4.4721 5.6569
   1 4 5.6569 4.4721
   0 5 8.2462 2.8284
*/

