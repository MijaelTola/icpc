#include <bits/stdc++.h>

using namespace std;

int n;
int v[100010];
int st[300010];

void update(int pos,int value){
	for (st[pos+=n]= value; pos > 1; pos>>=1)
		st[pos>>1] = max(st[pos],st[pos^1]); 
}

// interval[l,r)
int query(int l,int r){
	int ans = 0;
	r++;
	for (l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1) ans = max(ans, st[l++]);
		if(r&1) ans = max(ans,st[--r]);
	}
	return ans;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        update(i, v[i]);
    }
    

    for (int i = 0; i < n; ++i) {
        int a = i, b = min(n,i + v[i] + 1);
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(query(i + 1, mid) > v[i]) b = mid;
            else a = mid;
        }
        cout << abs(a - i) << " ";
    }
    
    cout << "\n";
   
    return 0;
}

