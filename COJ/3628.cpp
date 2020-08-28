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
    ios::sync_with_stdio(false); cin.tie(0);
    string x,y;
 //   cin.ignore();

    while(getline(cin,x) and getline(cin,y)){
        string a = "";
        string b = "";
        a += x[0],b +=  y[0];
        //cout << a.size() << " " << b.size() << endl;
        for (int i = 1; i < max((int)x.size(),(int)y.size()); ++i){
            if(i < (int)x.size() and x[i-1] == ' ')  a += x[i];
            if(i < (int)y.size() and y[i-1] == ' ') b += y[i];
        }
        //cout << a << " " << b << endl;
        if(a == b) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
    return 0;
}

