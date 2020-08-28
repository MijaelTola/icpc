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

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    string s;int n;
    cin >> s >> n;
    double average = 0;
    cout << "Tournament: " << s  << "\n";
    cout << "Number of players: " << n << "\n";
    cout << "New ratings:" << endl;
    for (int i = 0; i < n; ++i){
        string l;
        double x,w,w1,k;
        cin >> l >>x >> w >> w1 >> k;
        cout << l<<  " " << x+k*(w-w1) <<"\n";
        average += x;
    }
    cout.precision(0);
    cout << fixed << "Media Elo: " << average/n << "\n";
    return 0;
}

