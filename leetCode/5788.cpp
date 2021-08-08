#include <bits/stdc++.h>

using namespace std;

string largestOddNumber(string num) {
    string ans = "", cur = "";
    int id = -1;
    for (int i = 0; i < (int)num.size(); ++i) {
        char c = num[i];
        int d = c - '0';
        if(d & 1) id = i;
    }

    for (int i = 0; i <= id; ++i)
        ans += num[i];
    return ans;
}

int main() {
    cout << largestOddNumber("52");
    return 0;
}

