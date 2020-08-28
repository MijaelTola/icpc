#include <bits/stdc++.h>

using namespace std;

struct MafiaGame {
    
    int lose[510];

    double probabilityToLose(int N, vector <int> decisions) {
        memset(lose, 0, sizeof lose);
        for (int x: decisions) 
            lose[x]++;

        int mx = 0;
        for (int i = 0; i < 510; ++i)
            mx = max(mx, lose[i]);

        int cnt = 0;
        for (int i = 0; i < 510; ++i) 
            cnt += mx == lose[i];

        if(cnt == 1) return 1.0;
        double ans = 1.0 / cnt;
        while(cnt > 1) {
            cnt = N % cnt;
            if(cnt == 0) return 0;
        }

        return ans;
        
    }

};
int main() {
    
    return 0;
}

