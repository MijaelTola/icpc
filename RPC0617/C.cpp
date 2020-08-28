#include <bits/stdc++.h>

using namespace std;

int n;
int da,db,dm;
int v[30][3];
int f(int pos, int a,int d, int m){
    if(pos == n){
        if(da == a and db == d and m == db) return 1;
        return 0;
    }
    bool ans = 0;

    ans |= f(pos + 1, a + v[pos][0], v[pos][1] + d, v[pos][2] + m);
    ans |= f(pos + 1, a,d,m);
    return ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);  
    int t; cin >> t;

    while(t--){
        cin >> da >> db >> dm >> n; 
        for (int i = 0; i < n; ++i){
            string x;
            cin >>  x;
            for (int j = 0; j < 3; ++j)
                cin >> v[i][j];
        }
        if(f(0,0,0,0)) cout << "POSSIBLE\n";
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}

