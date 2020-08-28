#include <iostream>

using namespace std;

double pos[1010];
int main() {

#ifdef JUDGE
    freopen("input.txt","rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    double a,b,c;
    cin >> a >> b >> c;
    cout.precision(10);
    cout << fixed << (a / 2 + b / 2 + c / 2) / 3 << "\n";
    return 0;
}

