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

map<int,string> mp;
int main(){
    int n; cin >> n;
    while(n--){
        string c,name;
        int num;
        cin >> c;
        if(c == "add"){ 
           cin >> num >> name;
           mp[num] = name;
        }
        if(c == "find"){
            cin >> num;
            if(mp[num] == "") cout << "not found" << endl;
            else cout << mp[num] << endl;
        }
        if(c == "del"){cin >> num; mp[num] = "";}
    }
    return 0;
}

