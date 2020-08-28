#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int tree[1000100];
int A[1000100];
void build(int node, int start, int end)
{
    if(start == end) tree[node] = A[start];
    else
    {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] * tree[2*node+1];
    }
}
void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        A[idx] = val;
        tree[node] = val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            update(2*node, start, mid, idx, val);
        }
        else
        {
            update(2*node+1, mid+1, end, idx, val);
        }
        tree[node] = tree[2*node] * tree[2*node+1];
    }
}
int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        return 1;
    }
    if(l <= start and end <= r)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 * p2);
}

int main() {
	int n,q;
	cin >> n >> q;

	for (int i = 0; i < n; ++i){
		ll x; cin >> x;
		if(x < 0) A[i] = -1;
		else if(x > 0) A[i] = 1;
		else A[i] = 0;
	}
	build(1,0,n-1);

	for (int i = 0; i < q; ++i)
	{
		ll c,a,x;
		cin >> c >> a >> x;
		if(c == 1) cout << query(1,0,n-1,a-1,x-1) << endl;
		else{
			if(x < 0) update(1,0,n-1,a-1,-1); 
			else if(x > 0) update(1,0,n-1,a-1,1); 
			else update(1,0,n-1,a-1,0); 
		} 
	}
	return 0;
}