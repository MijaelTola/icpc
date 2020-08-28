#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll v[100010];
int n;

int bs(int x){
    int a = -1, b = n;
    while(b - a > 1){
        int mid = (a+b)>>1;
        if(v[mid] >= x) b = mid;
        else a = mid;
    }
    return b;
}
int main(){
    ll d;
    cin >> n >> d;
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v,v+n);
    int ans = -1;
    for (int i = 0; i < n; ++i){
        ll x = v[i] + d;
        int pos = bs(x);
        int dis = pos - i;
        //cout << i << " " << pos << " " << dis << endl;
        ans = max(ans,dis);
    }
    cout << ans+1 << endl;
    return 0;
}
