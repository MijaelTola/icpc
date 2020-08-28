#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string s; cin >> s;
    
    int rank = 25;
    int stars = 0;
    int win = 0;
    int needed = 2;
    for (int i = 0; i < (int)s.size(); ++i) {
        char c = s[i];
        if(rank <= 25 and rank >= 21) {
            needed = 2;
            if(c == 'W') {
                win++;
                if(win >= 3) stars += 2;
                else stars++;
                if(stars + 1 > needed and win >= 3) {
                    stars = 1;
                    rank--;
                }
                if(stars > needed) {
                    stars = 1;
                    rank--;
                }
            } else {
                win = 0;
            }
        } 
        if(rank <= 20 and rank >= 16) {
            needed = 3;
            if(c == 'W') {
                win++;
                if(win >= 3) stars += 2;
                else stars++;
                if(stars + 1 > needed and win >= 3) {
                    stars = 1;
                    rank--;
                }
                if(stars > needed) {
                    stars = 1;
                    rank--;
                }
            } else {
                win = 0;
                if(stars < 0 and rank > 20) {
                    stars--;
                    rank++;
                    stars = needed - 1;
                }
            }
        }

        if(rank <= 15 and rank >= 11) {
            needed = 4;
            if(c == 'W') {
                win++;
                if(win >= 3) stars += 2;
                else stars++;
                if(stars + 1 > needed and win >= 3) {
                    stars = 1;
                    rank--;
                }
                if(stars > needed) {
                    stars = 1;
                    rank--;
                }
            } else {
                win = 0;
                stars--;
                if(stars < 0 and rank > 20) {
                    rank++;
                    stars = needed - 1;
                }
            }
        }

        if(rank <= 10 and rank >= 1) {
            needed = 5;
            if(c == 'W') {
                win++;
                if(win >= 3 and rank <= 6) stars += 2;
                else stars++;
                if(stars + 1 > needed and win >= 3) {
                    stars = 1;
                    rank--;
                }
                if(stars > needed) {
                    stars = 1;
                    rank--;
                }
            } else {
                win = 0;
                stars--;
                if(stars < 0 and rank <= 1) {
                    rank++;
                    stars = needed - 1;
                }
            }
        }
        cout << rank << " " << stars << " " << win << " " << needed << " " << c<< "\n";
    }
    cout << rank << "\n";
    return 0;
}

