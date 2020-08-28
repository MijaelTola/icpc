#include <bits/stdc++.h>

using namespace std;


/*
    1
   1 1
  1 1 1
 1 1 1 2
 * */
int main(){
    long long f,b;
    while(cin >> f >> b and f and b){
        long long t = (f * (f + 1)) / 2;
        f -= b;
        f++;
        cout << t - (f * (f + 1)) / 2 << "\n";
    }
    return 0;
}

