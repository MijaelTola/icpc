#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n,k;
    while(cin >> n >> k){
        if(k <= (n+1)/2) cout << 2*k-1;
        else cout << (k-(n+1)/2)*2;
        puts("");
    }
    return 0;
}
