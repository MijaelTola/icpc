#include <bits/stdc++.h>

using namespace std;

int n;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    if(n == 1) {
        cout << "1\n1\n";
        return 0;
    }
    if(n == 2) {
        cout << "1 2\n";
        cout << "2 1\n";
        return 0;
    }
    if(n == 3) {
        cout << "2 3 1" << "\n";
        cout << "3 1 2" << "\n";
        return 0;
    }
    int mid = (n + 1) / 2;
    
    for (int i = 2; i <= mid; ++i)
        cout << i << " ";
    cout << 1 << " ";

    for (int i = mid + 2; i <= n; ++i)
        cout << i << " ";
    cout << mid + 1<< "\n";
    
    cout << n << " ";
    for (int i = 1; i < n; ++i)
        cout << i << " ";
    cout << "\n";
    
    return 0;
}

