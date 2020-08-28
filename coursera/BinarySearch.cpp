#include <iostream>

using namespace std;
int v[100010];

int main(){
    
    int n; cin >> n;
    int m;
    for (int i = 0; i < n; ++i) cin >> v[i];
    cin >> m;
    for (int i = 0; i < m; ++i){
        int x;cin >> x;
        int a = -1,b = n-1;
        while(b - a > 1){
            int mid = (a+b)>>1;
            if(v[mid] >= x) b = mid;
            else a = mid;
        }
        if(v[b] == x) cout << b << endl;
        else cout << -1 << endl;
    }
    return 0;
}
