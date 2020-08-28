#include <bits/stdc++.h>

using namespace std;

map<int,int> mp;
int main() {
    
    mp[1] = 31;
    mp[2] = 28;
    mp[3] = 29;
    mp[4] = 30;
    mp[5] = 31;
    mp[6] = 30;
    mp[7] = 31;
    mp[8] = 30;
    mp[9] = 30;
    mp[10] = 31;
    mp[11] = 30;
    mp[12] = 31;
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    
    if(mp[a] == b) puts("1");
    else puts("0");
    return 0;
}

