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

int main(){
    
    string x; cin >> x;
    string a = "";
    string b = "";
    for (int i = 0; i < (int)x.size(); ++i)
        if(x[i] == 'a' or x[i] == 'e' or x[i] == 'i' or x[i] == 'u' or x[i] == 'o') a += x[i];
    
    for (int i = x.size(); i >= 0; --i)
        if(x[i] == 'a' or x[i] == 'e' or x[i] == 'i' or x[i] == 'u' or x[i] == 'o') b += x[i];
    if(a == b) cout << "S";
    else cout << "N";
    cout << endl;
    return 0;
}

