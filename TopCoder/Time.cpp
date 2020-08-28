#include <bits/stdc++.h>

using namespace std;

struct Time {

    string whatTime(int seconds) {
        int s = seconds % 60;
        int m = seconds / 60;
        int h = m / 60;
        m %= 60;
        string ans = "" + to_string(h) + ":" + to_string(m) + ":" + to_string(s);
        return ans;
    }
};
int main() {
    Time t;
    cout << t.whatTime(3661) << "\n";
    return 0;
}

