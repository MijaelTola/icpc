#include <iostream>
#include <cstring>
#include <string> 
#include <algorithm>

using namespace std;

pair<int,int>pos [260];
int main() {
#ifdef JUDGE
    freopen("input.txt","rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int w,h;
    cin >> w >> h;
    for (int i = 0; i < h; ++i) 
        for (int j = 0; j < w; ++j) {
            char x; cin >> x;
            pos[x].first = i;
            pos[x].second = j;
        }


    int k = 3;
    int ans = 1e9;
    string lan = "";
    while(k--) {
        string rd = "";
        string cur = "";
        string clan;
        cin >> clan >> cur;
        while(cur != "%TEMPLATE-END%") {
            cin >> cur;
            if(cur != "%TEMPLATE-END%")rd += cur;
        }
        int sum = 0;
        for (int i = 1; i < (int)rd.size(); ++i) {
            int x1 = pos[rd[i - 1]].first;
            int y1 = pos[rd[i - 1]].second;
            int x2 = pos[rd[i]].first;
            int y2 = pos[rd[i]].second;
            sum += max(abs(x1 - x2), abs(y1 - y2));
        }
        if(sum < ans) {
            ans = sum;
            lan = clan;
        }
    }
    cout << lan << "\n";
    cout << ans << "\n";
    return 0;
}

