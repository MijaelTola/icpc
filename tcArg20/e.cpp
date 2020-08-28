#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> v(n);
    int l = 0, r = n - 1;

    for (int &x: v)
        cin >> x;

    int da = 0, db = 0, a = 0, b = 0;

    while(l < r) {
        if(da + v[l] < db + v[r]) {
            da += v[l];
            l++;
            a++;
        } else {
            db += v[r];
            r--; 
            b++;
        }
    }
    
    if(da <= db) a++;
    else b++;
    cout << a << " " << b << "\n";
    return 0;
}

