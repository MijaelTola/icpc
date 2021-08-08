#include <bits/stdc++.h>

using namespace std;

//1 1 1
//1 1 2
//1 2 2
//1 2 3
//1 3 3
//2 2 2
//2 2 3
//2 3 3
//3 3 3
//
//
//1 1 1 1
//1 1 1 2
//1 1 2 2
//1 2 2 2
//1 2 2 3
//1 2 3 3
//1 2 3 4
//1 2 4 4
//1 3 3 4
//1 3 4 4
//1 4 4 4

int n;
int f(int pos, int last, string t) {
    if(pos == n) {
        cout << t << endl;
        return 1;
    }
    int ans = 0;
    ans += f(pos + 1, last, t + to_string(last));
    if(last + 1 <= n) {
        ans += f(pos + 1, last + 1, t + to_string(last + 1));
    }
    return ans;
}
int main() {
    
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += f(1, i, to_string(i));
    cout << ans << "\n";
    return 0;
}

