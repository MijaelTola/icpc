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

int st[4*500010];
ll A[500010];
int n;
void build(int node, int l, int r){
    if(l == r){ st[node] = l; return;}
    int mid = (r+l)>>1;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    int p1 = st[2*node];
    int p2 = st[2*node+1];
    st[node] = (A[p1] <= A[p2]) ? p1 : p2;
}

int query(int node, int l, int r, int i, int j){
    if(i > r or j < l) return -1;
    if(l>= i and r <= j) return st[node];
    int mid = (l+r)>>1;
    int p1 = query(2*node,l,mid,i,j);
    int p2 = query(2*node+1,mid+1,r,i,j);
    if(p1 == -1) return p2;
    if(p2 == -1) return p1;
    return (A[p1] <= A[p2]) ? p1 : p2;
}

int query(int i,int j){ return query(1,0,n-1,i,j);}

ll f(int l, int r, ll mn){
    if(l > r) return 0LL;
    if(l == r) return A[l]-mn;
    int pos = query(l,r);
    ll ans = f(l,pos-1,A[pos]) + f(pos+1,r,A[pos]);
    if(A[pos] > mn)  return ans+A[pos]-mn;
    return ans;
}
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];
    build(1,0,n-1);
    cout << f(0,n-1,0LL) << "\n";
    return 0;
}

