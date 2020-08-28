#include <bits/stdc++.h>

using namespace std;

pair<int,int> f(int x) {
    int a = 0, b = 0;
    for (int y: {2, 3}) {
        while(x % y == 0) {
            x /= y;
            if(y == 2) a++;
            else b++;
        }
    }
    if(x > 1) return {-1, -1};
    return {a,b};
}

int main() {

    int n,m;
    cin >> n >> m;
    
    if(m % n != 0) return cout << "-1\n", 0;
    auto p = f(m / n);

    if(p.first == -1) return cout << "-1\n", 0;

    cout << p.first + p.second << "\n";
    return 0;
}

