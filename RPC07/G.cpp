#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

int main(){
    
    string n; 
    while(cin >> n and n != "END"){
    string ans = "";
    bool flag = false;
    for (int i = n.size()-1; i >= 0; --i){
        if(!flag){
            int x = n[i] - '0';
            if(x > 0) {
                x--;
                ans += char(x+'0');
                flag = true;
                continue;
            }
        }
        ans += n[i];
    }
    reverse(ans.begin(),ans.end());
    if(ans[0] ==  '0') cout << 0 << endl;
    else cout << ans << endl;
    }
    return 0;
}

