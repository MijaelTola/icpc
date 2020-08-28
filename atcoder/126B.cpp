#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    cin >> s;

    int a = (s[0] - '0') * 10 + (s[1] - '0');
    int b = (s[2] - '0') * 10 + (s[3] - '0');
    int c = a * 100 + b;
    set<int> yymm, mmyy, amb;

    for (int i = 13; i <= 99; ++i) 
        for (int j = 1; j <= 12; ++j) {
            yymm.insert(i * 100 + j);
            mmyy.insert(j * 100 + i);
        }
    
    for (int i = 1; i <= 12; ++i) 
        for (int j = 1; j <= 12; ++j)
            amb.insert(i * 100 + j);
    
    if(yymm.count(c) or (a == 0 and b >= 1 and b <= 12)) return puts("YYMM"),0;
    if(mmyy.count(c) or (b == 0 and a >= 1 and a <= 12)) return puts("MMYY"),0;
    if(amb.count(c)) return puts("AMBIGUOUS"),0;
    puts("NA");       
    
    return 0;
}

