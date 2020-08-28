#include <bits/stdc++.h>

using namespace std;

struct BallsOnAMeadow {
    int count(string meadow) {
        
        int ans = 0;
        for (int i = 0; i < (int)meadow.size(); ++i) {
            if(meadow[i] == '(') ans++;
            else if(meadow[i] == ')' and meadow[i - 1] == '|') ans++;
        }
        return ans;
    }
};

int main() {
    
    BallsOnAMeadow m;
    cout << m.count(".(|||.()(||||||)") << "\n";;
    return 0;
}

