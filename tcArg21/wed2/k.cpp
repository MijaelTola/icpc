#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,m;
    cin >> n >> m;
    int big = 100019 - n + 2;
    cout << big + 2 << " " << big + 2<< "\n";;
    cout << "1 2 " << big  << "\n";
    for(int i=3; i<=n;i++)
        cout << i - 1 << " " << i  << " 1\n";
    m-= (n-1);
    int a = 1 , b= 3;
    while(m--){
        cout << a << " " << b << " 1000000000\n";
        b++; 
        if(b > n)
            a++, b = a +2;
    }
    return 0;
}

