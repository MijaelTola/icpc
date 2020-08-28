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
int counter[1000100][28];
pair<int,int> pos[28][1000100];
string x;
int BWTMatching(string pattern){
    int top = 0; int bottom = x.size()-1;
    int p = pattern.size()-1;
    while(top <= bottom){
        if(p >= 0){
            char symbol = pattern[p]; p--;
            if(counter[bottom+1][symbol-'A']>0){
                top = pos[symbol-'A'][cnt2[1]].first+counter[top][symbol-'A'];
                bottom = pos[symbol-'A'][cnt2[1]].first+counter[bottom+1][symbol-'A']-1;
            }else return 0;
        }else return bottom - top + 1;
   }
    return 0;   
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    getline(cin,x);
    for (int i = 0; i < (int)x.size(); ++i)
        alpha[x[i]-'A']++;
    string p = x;
    sort(p.begin(),p.end());
    memset(alpha,0,sizeof alpha);
    for (int i = 0; i < (int)x.size(); ++i){
        char v = x[i];
        if(v != '$'){
            if(v != ' '){
                int t = ++alpha[v-'A'];
                cnt[i] = t;
                pos[v-'A'][t].second = i;
            }else{
                int t = ++alpha[26];
                cnt[i] = t;
                pos[26][t].second = i;
            }
        }
        if(p[i] != '$'){
            if(p[i] != ' '){
                int t = ++alp[p[i]-'A'];
                cnt2[i] = t;
                pos[p[i]-'A'][t].first = i;
            }else{
                int t = ++alp[26];
                cnt2[i] = t;
                pos[26][t].first = i;
            }
        }
      
    }

    for (int i = 1; i <= (int)x.size(); ++i){
        if(x[i-1]!= '$') counter[i][x[i-1]-'A'] = 1;
        else counter[i][27] = 1;
        for (int j = 0; j < 28; ++j) counter[i][j] += counter[i-1][j];
    }
    int q; cin >> q;
    while(q--){
        string pattern; cin >> pattern;
        cout << BWTMatching(pattern) << " ";
    }
    return 0;
}
