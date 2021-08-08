#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
    
        bool flag = 1;

        auto check = [&] (char c) {
            for (auto ct: brokenLetters)
                if(ct == c) return 1;
            return 0;
        };

        int ans = 0;
        for (char c: text) {
            if(c == ' ') {
                ans += flag;
                flag = 1;
            } else {
                flag &= !check(c);
            }
        }
        ans += flag;
        return ans;
    }
};

int main() {

    return 0;
}

