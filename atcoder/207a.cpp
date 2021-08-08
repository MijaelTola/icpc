#include<bits/stdc++.h>

using namespace std;

int main() {

    long long a,b,c,d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    long long da = a, db = 0;
    int lim = 1e8;

    //a + i * b   i * 
    while(lim--) {
        if(d * db >= da) 
            return cout << ans << "\n", 0;
        ans++;
        da += b; 
        db += c;
    }
    cout << "-1\n";
    return 0;
}
