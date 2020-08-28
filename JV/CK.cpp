#include <bits/stdc++.h>

using namespace std;

int st[1000001];
int A[1000001];
int n;
int left(int p){return p << 1;}
int right(int p){ return (p<<1)+1;}
void build(int p,int L, int R){
	if(L==R) st[p] = L;
	else{
		build(left(p),L,(L+R)/2);
		build(right(p),(L+R)/2+1,R);
		int p1 = st[left(p)]; int p2 = st[right(p)];
		st[p] = (A[p1] <= A[p2]) ? p1 : p2;
	}
}

int rmq(int p,int L, int R,int i, int j){
	if(i > R or j < L) return -1;
	if(L >= i and R <= j) return st[p];
	int p1 = rmq(left(p),L,(L+R)/2,i,j);
	int p2 = rmq(right(p),(L+R)/2+1,R,i,j);
	if(p1 == -1) return p2;
	if(p2 == -1) return p1;
	return (A[p1] <= A[p2]) ? p1 : p2;
}

void update(int p, int L, int R, int idx, int val)
{
	if(L == R){
		 A[idx] = val;
		 st[p] = L;
	}else
	{
		if(L <= idx and idx <= (L+R)/2) update(left(p),L,(L+R)/2,idx,val);
		else update(right(p),(L+R)/2+1, R, idx,val);
		int p1 = st[left(p)]; int p2 = st[right(p)];
		st[p] = (A[p1] <= A[p2]) ? p1 : p2;
	}
}
int main(){
 	int q;
	cin >> n >> q;;
	for (int i = 0; i < n; ++i) cin >> A[i];
	build(1,0,n-1);
	for (int i = 0; i < q; ++i)
	{
		char c;int x,y; cin >> c >> x >> y;
		if(c == 'M') cout << A[rmq(1,0,n-1,x-1,y-1)] << endl;
		else if(c == 'C') update(1,0,n-1,x-1,y);
		
	}
	return 0;
}