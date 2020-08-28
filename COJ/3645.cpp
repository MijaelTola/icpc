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

using namespace std;

typedef long long ll;

int x[100010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int a,c,m;
    while(cin >> a >> c >> m >> x[0]){
        set<int> rep;
        rep.insert(x[0]);
       // cout << x[0] << " ";
        int i = 1;
        while (true){
            x[i] = (a*x[i-1]+c)%m;
         //   cout << x[i] << " ";
            if(rep.count(x[i])) break;
            rep.insert(x[i]);
            i++;
        }
       // cout << endl;
        int p = i-2;
        while(x[i] != x[p] and p >= 0)p--;
        int rest;
        int loop;
        //cout << p << " p" << endl;
        if(p == -1){
            loop = 1;
            rest = i-1;
        }else{
            loop = i - p;
            rest = p;
        }
        if((int)rep.size() == m) cout << "YES ";
        else cout <<  "NO ";
        cout << rep.size()  << " " << rest << " " << loop<< "\n"; 
    }
    return 0;
}

