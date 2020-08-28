#include <iostream>

using namespace std;

int v[100020];

long long f(int a, int b) {
    long long ans = -1e9;
    long long sum = 0;

    for (int i = a; i <= b; ++i){
        sum += v[i];
        sum = max(sum,0LL);
        ans = max(ans,sum);
    }
    return ans;
}
int main(){

    int t;

    cin >> t;
    while(t--) {
        int n; 
        cin >> n;

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            sum += v[i];
        }
    
        long long x = f(0, n - 2);
        long long y = f(1, n - 1);

        if(x >=sum or y >= sum) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
