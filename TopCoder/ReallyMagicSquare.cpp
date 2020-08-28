#include <bits/stdc++.h>

using namespace std;

struct ReallyMagicSquare {
    int ans[30][30];
    int n;
    vector <int> reconstruct(vector <int> topRow, vector <int> mainDiagonal) {
        n = topRow.size();
            
        for (int i = 0; i < n; ++i) {
            ans[0][i] = topRow[i];
            ans[i][i] = mainDiagonal[i];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                :e        
            }
        }
        return {};
    }
};
int main() {

    return 0;
}

