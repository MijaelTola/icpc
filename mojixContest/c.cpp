#include <bits/stdc++.h>

using namespace std;

long long g(int x) {
    if(x == -1 or x == 0) return 1;
    return x * g(x - 2);
}
int main() {

    for (int i = 0; i < 40; ++i) 
        cout << i << ": " << g(i) << "\n";
    return 0;
}

