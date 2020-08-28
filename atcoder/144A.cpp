#include <bits/stdc++.h>

using namespace std;

int main() {

    int a,b;
    cin >> a >> b;
    if(a > 9 or b > 9) return puts("-1"),0;
    cout << a * b << "\n";
    return 0;
}

