#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int v[1000010];
int way[1000010];
vector<int> ans;
int main(){
    for(int i = 0; i < 1000010; ++i) v[i] = 1e8;
    int n; cin >> n;
    v[1] = 0;
    way[1] = 0;
    way[0] = -1;
    for (int i = 1; i <= n; ++i){
        if(i+1 <= n){
            if(v[i]+1 < v[i+1]){
                v[i+1] = v[i]+1;
                way[i+1] = i;
            }
        }
        if(i*2 <= n){
            if(v[i]+1 < v[i*2]){
                v[i*2] = v[i]+1;
                way[i*2] = i;
            }
        }
        if(i*3 <= n){
            if(v[i]+1 < v[i*3]){
                v[i*3] = v[i]+1;
                way[i*3] = i;
            }
        }
    }
    cout << v[n] << endl;
    int v = n;
    while(way[v] != -1){
        ans.push_back(v);
        v = way[v];
    }
    for(int i = ans.size()-1; i >= 0; --i) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
