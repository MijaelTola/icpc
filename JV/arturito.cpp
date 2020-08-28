#include <iostream>
#include <queue>
#include <cmath>

using namespace std;


struct cmp{
    bool operator()(const pair<pair<int,int> ,int > a, const pair<pair<int,int>,int> b){
        return a.second < b.second;
    }
};
int main(){

    int n; cin >> n;
    priority_queue<pair<pair<int,int> ,int >,vector<pair<pair<int,int> ,int > >,cmp > q;
    while(n--){
        int x,y,w; cin >> x >> y >> w;
        q.push({{x,y},w});
    }
    int a,b,r,k;
    cin >> a >> b >> r >> k;
    int ans = 0;
    int c = 0;
    while(k and !q.empty()){
        int x = q.top().first.first;
        int y = q.top().first.second;
        int w = q.top().second;
        q.pop();
        int dis = sqrt((x-a)*(x-a)+(y-b)*(y-b));
        if(dis <= r){
            ans += w;
            c++;k--;
        }
    }
    cout << c << " " << ans <<endl;
    return 0;
}
