#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;
struct pack{
    int idx;
    int pross;
    pack(){ idx= 0;pross = 0;}
    pack(int id, int p){idx = id; pross = p;}
};
int ans[100010];
int main(){
    // in out
    deque<pack > q;
    vector<pair<int,int> > v;
    int n,s; cin >> s >> n;

    for (int i = 0; i < n; ++i){
        int ta,pt;
        cin >> ta >> pt;
        v.push_back({ta,pt});
    }
    ll actual = 0;
    ll tout = v[0].second;
    ans[0] = v[0].first;
    int pos = 1;
    q.push_back(pack(0,0));
    while(pos <= (int)v.size()){
        cout << actual << " " << tout  << " time"<< endl;
        if(actual == tout){
            q.pop_front();
            cout << q.front().idx << " id" << endl;
            ans[q.front().idx] = actual;
            tout += q.front().pross;
        }
        if(v[pos].first <=  actual){
            if((int)q.size() > s) ans[pos] = -1;
            q.push_back(pack(pos,v[pos].second));
            pos++;
        }
        actual++;
    }

    for (int i = 0; i < n;++i) cout << ans[i] << endl;
    return 0;
} 
