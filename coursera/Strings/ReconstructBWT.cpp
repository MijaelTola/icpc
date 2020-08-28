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
#include <cmath>
#include <deque>
#include <string> 
#include <sstream>
#include <cstdlib>

using namespace std;

typedef long long ll;

int alpha[28];
int alp[28];
int cnt[1000100];
int cnt2[1000100];
pair<int,int> pos[28][1000100];
int main(){
    string x;// cin >> x;
    getline(cin,x);
    for (int i = 0; i < (int)x.size(); ++i)
        alpha[x[i]-'A']++;
    
    string p = x;
    sort(p.begin(),p.end());
    memset(alpha,0,sizeof alpha);
    for (int i = 0; i < (int)x.size(); ++i){
        char v = x[i];
        if(v != '$'){
            int t = ++alpha[v-'a'];
            cnt[i] = t;
            pos[v-'a'][t].second = i;
        }
        if(p[i] != '$'){
            int t = ++alp[p[i]-'a'];
            cnt2[i] = t;
            pos[p[i]-'a'][t].first = i;
        }
      
    }
    for (int i = 0; i < (int)p.size(); ++i) 
        if(p[i] != '$')cout << p[i] << " " << cnt2[i] << endl;
        else cout << "$ 0\n";
    string ans = "";
    int t = 0;
    while(x[t] != '$'){
        if(x[t] != ' '){
            ans += x[t];
            t = pos[x[t]-'a'][cnt[t]].first;
        }else{
            ans += " ";
            t = pos[26][cnt[t]].first;
        }
    }
    reverse(ans.begin(),ans.end());
    ans += x[t]; 
    cout << ans << endl;
    return 0;
}
