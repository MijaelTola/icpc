#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int ans = 0;
    for (int x = 0; x <= 1; ++x){
        for (int y = 0; y < 2; ++y){
            for (int z = 0; z < 2; ++z){
                if((x or !y or !z) and (x or y) and (!x or !y))
                    ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

