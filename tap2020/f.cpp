#include <bits/stdc++.h>

using namespace std;

int points[2];
int wins[2];

int main() {

    auto printCurrent = [&] (int gl, int pl, int gr, int pr, bool who) {
        if(!who) printf("%d (%d*) - %d (%d)\n", gl, pl, gr, pr);
        else printf("%d (%d) - %d (%d*)\n", gl, pl, gr, pr);
    };

    auto printFinal = [&] (int a, int b, int who) {
        if(!who) printf("%d (winner) - %d\n", a, b);
        else printf("%d - %d (winner)\n", a, b);
    };

    string s;

    cin >> s;


    int server = 0;

    for (auto c: s) {
        if(c == 'S') {
            points[server]++;

            if(points[server] >= 5 and points[server] - points[1 - server] >= 2) {
                wins[server]++;
                points[0] = points[1] = 0;
            }

            if(points[server] >= 10) {
                wins[server]++;
                points[0] = points[1] = 0;
            }
        }
        if(c == 'R') {
            server ^= 1;
            points[server]++;
            if(points[server] >= 5 and points[server] - points[1 - server] >= 2) {
                wins[server]++;
                points[0] = points[1] = 0;
            }

            if(points[server] >= 10) {
                wins[server]++;
                points[0] = points[1] = 0;
            }
        }
        
        if(c == 'Q') {
            if(wins[0] > wins[1]) {
                if(wins[0] >= 2) {
                    printFinal(wins[0], wins[1], 0);
                    continue;
                }
            } else {
                if(wins[1] >= 2) {
                    printFinal(wins[0], wins[1], 1);
                    continue;
                }
            }
            printCurrent(wins[0], points[0], wins[1], points[1], server);

        }

    }

    return 0;
}


