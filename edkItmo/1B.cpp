#include <iostream>

using namespace std;

int main() {
    #ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0);
    long long a,b;
    cin >> a >> b;
    cout << a + b *b << "\n";
    return 0;
}

