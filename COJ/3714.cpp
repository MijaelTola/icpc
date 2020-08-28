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
#include <sstream>
using namespace std;

typedef long long ll;

int alpha[28];
int main(){
    //ios::sync_with_stdio(false); cin.tie(0);
    string s; 
    while(cin >> s){
        for (int i = 0; i < 28; ++i) alpha[i] = 0;
        int  cnt = 0;
        string x = "";
        for (int i = 0; i < (int)s.size(); ++i){
            if(alpha[s[i]-'a'] == 0) alpha[s[i]-'a'] = ++cnt;
            string y = "";
            int a = alpha[s[i]-'a'];
            while(a > 0){
                y = char((a%10)+'0') + y;
                a /= 10;
            }
            //cout << cnt << " " << y << endl;
            x += y;
        }
        //cout << x << endl;
        string ans = "";
        for(int i = 0; i < (int)x.size(); ++i){
            if(x[i] == '2'){ ans += "5";continue;}
            if(x[i] == '5'){ ans += "2";continue;}
            if(x[i] == '6'){ ans += "9";continue;}
            if(x[i] == '9'){ ans += "6";continue;}
            ans += x[i];
        }
        cout << ans << "\n";
    }
    return 0;
}

