#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,d;
    cin >> n >> d;

    int ans = 0;
    while(n--) {

        double x,y;
        cin >> x >> y;
        if(d >= sqrt(x * x + y * y)) ans++;
    }
    cout << ans << "\n";
    return 0;
}

