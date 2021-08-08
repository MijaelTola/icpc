#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {

        int ans = 0;

        int last = 0;
        for (int i = 0; i < (int)rungs.size(); ++i) {
            int d = rungs[i] - last;
            if(d > dist) {
                d /= dist;
            }
        }

        return ans;
    }
};

int main() {

    return 0;
}

