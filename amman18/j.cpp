#include <bits/stdc++.h>

using namespace std;
/*
 *
 2 7 7
 111

 010
 011
 100
 101
 110
 111

 1101

 0001
 0010
 0011
 0100
 0101
 0110
 0111
 1000
 1001
 1010
 1011
 1100
 1101
 1110
 1111

 01100100
 10010110 150
 10010101 149
 10010100 148
 10010011 147
 10010010 146
 10010001 145
 10010000 144
 10001111 143
 10011111 142
 10011111 159
 10011111
 01100100 100

  * */
void print(int cur) {
    cout << cur << " this is the one\n";
    for (int i = 10; i >= 0; i--)
        if(cur & (1 << i)) cout << 1;
        else cout << 0;
    cout << "\n";
}
int main() {
    /*int a = 0;
    for (int i = 300; i <= 767; ++i) {
        a = a | i;
    }
    cout << a << "\n";
    print(a);*/
    int a,b,k;
    cin >> a >> b >> k;
    int ans = 0;
    int id = 0;
    int jd = 0;
    int cur = 0;
    for (int i = a; i <= b; ++i) {
        for (int j = i; j <= b; ++j)  {
            int da = 0;
            for (int k = i; k <= j; ++k) {
                da = da | k;

            }
            if(da <= k) {
                if(j - i + 1 > ans) {
                    cur = da;
                    ans = max(ans, j - i + 1);
                    id = i;
                    jd = j;
                }
            }
        }
    }
    cout << ans << "\n";
    cout << id << " " << jd << "\n";
    cout << cur << " cur\n";
    print(id);
    cout << " ";
    print(cur);
    cout << " my cost\n";
    print(k);
    cout << " ans\n";
    print(ans);
    /* for (int i = id; i <= jd; ++i) {
       for (int j = 8; j >= 0; j--) {
       if(i & (1 << j)) cout << 1;
       else cout << 0;
       }
       cout << "\n";
       }*/
    return 0;
}

