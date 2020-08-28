#include <bits/stdc++.h>

using namespace std;

vector<int> v;

bool zero(int x) {
    while(x > 0) {
        int d = x % 10;
        if(!d) return 1;
        x /= 10;
    }
    return 0;
}
int main() {
    
    int n;
    cin >> n;
    int i = n;
    for (i = n + 1; zero(i); ++i) {}
    cout << i << "\n";
    return 0;
}

