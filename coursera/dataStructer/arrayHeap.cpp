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

ll v[100100];
int n;
vector<pair<int,int> > ans;

void siftdown(int i){
    int mx = i;
    int left = i*2;
    if(left <= n and v[left] < v[mx]) mx = left;
    int right = i*2+1;
    if(right <= n and v[right] < v[mx]) mx = right;
    if(mx != i){
        ans.push_back({i-1,mx-1});
        swap(v[i],v[mx]);
        siftdown(mx);
    }
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> v[i];
    for (int i = n/2; i >= 1; --i)
        siftdown(i);
    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); ++i)
        cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}
 
