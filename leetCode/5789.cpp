#include <bits/stdc++.h>

using namespace std;

int numberOfRounds(string startTime, string finishTime) {
    
    auto get = [&](string cur) {
        int a = stoi(cur.substr(0, 2));
        int b = stoi(cur.substr(3, 2));
        return a * 60 + b;
    };

    int ini = get(startTime);
    int fin = get(finishTime);

    if(fin < ini) fin += 60 * 24;

    int current = 0;
    int ans = 0;
    
    while(current < 3 * 60 * 24) {
        if(ini <= current and current <= fin) {
            cout << current << "\n";
            ans++;
        }
        current += 15;
    }
    return ans - 1;
}

int main() {

    cout << numberOfRounds("12:01", "12:44") << "\n";
    cout << numberOfRounds("20:00", "06:00") << "\n";
    cout << numberOfRounds("00:00", "23:59") << "\n";
    return 0;
}

