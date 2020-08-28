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
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main(){
    cout << "100\n";
    for (int i = 0; i < 100; ++i){
        int a = (rand()*random())%10+1;
        int b = rand()%a+1;
        cout << a << " " << b << "\n";
    }
    return 0;
}

