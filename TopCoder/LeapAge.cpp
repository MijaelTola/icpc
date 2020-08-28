#include <bits/stdc++.h>

using namespace std;

struct LeapAge {
    int getAge(int year, int born) {
        int ans = 0;
        for (int i = born + 1; i <= year; ++i)
            ans += (i % 4 == 0 and (i % 400 == 0 or i % 100 != 0));
        return ans;
    }
};

int main() {
    
    LeapAge l;
    cout << l.getAge(9700, 5795) << "\n";
    return 0;
}

