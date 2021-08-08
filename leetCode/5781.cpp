#include <bits/stdc++.h>

using namespace std;


string removeOccurrences(string s, string part) {
    while(1) {
        size_t f = s.find(part);
        if(f == string::npos) break;

        string ds = "";

        for (int i = 0; i < (int)f; ++i) {
            ds += s[i];
        }

        for (int i = f + part.size(); i < (int)s.size(); ++i)
            ds += s[i];
        s = ds;
    }
    return s;
}
int main() {

    return 0;
}

