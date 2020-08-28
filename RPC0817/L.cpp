#include <bits/stdc++.h>

using namespace std;

long long v[20010];

bool ver(long long a,long long b,long long c){
    if(b + c > a and a + b > c and a + b >  c) return 1;
    return 0;
}
int main(){
    
    int n; cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v,v + n);

    for (int i = 2; i < n; ++i){
        if(ver(v[i - 2],v[i - 1], v[i])) return cout << "possible\n",0;
    }
    cout << "impossible\n";
    return 0;
}

