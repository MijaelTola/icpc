#include <bits/stdc++.h>

using namespace std;

struct SRMCards{

    int maxTurns(vector <int> cards) {
        int ans = 0;
        bool vis[550];
        memset(vis, 0, sizeof vis);

        while(cards.size()) {
            int p = 0;

            while(vis[cards.back()]) cards.pop_back();
            
            while(p < (int)cards.size() - 1) {
                if(abs(cards[p] - cards.back()) <= 1) {
                    vis[cards[p]] = 1;
                    break;
                }
                p++;
            }
        
            if((int)cards.size()) {
                cards.pop_back();
                ans++;
            } 

        }
        return ans;
    }
};
int main() {
    SRMCards s;
    cout << s.maxTurns({11, 12, 102, 13, 100, 101, 99, 9, 8, 1}) << "\n";
    return 0;
}

