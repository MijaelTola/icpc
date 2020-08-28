#include <iostream>

using namespace std;

long long v[100010];

int main() {
    #ifdef JUDGE
    freopen("input.txt","rt", stdin);
    freopen("output.txt","wt", stdout);
    #endif
    
    cin >> v[0] >> v[1] >> v[2];
    int n; cin >> n;
    
    for (int i = 3; i <= n; ++i) 
        v[i] = v[i - 1] + v[i - 2] - v[i - 3];
    
    cout << v[n] << "\n";
    return 0;
}

