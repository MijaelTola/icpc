#include <bits/stdc++.h>

using namespace std;

int n,x,y;
int d[] = {31,28,31,30,31,30,31,31,30,31,30, 31};
bool cal[40][20];

int find(int day, int month) {
    int cd = day;
    int cm = month;
    int cnt = 0;
    int ans = 1e9;
    while(!cal[cd][cm]) {
        cd--;
        if(cd == 0) {
            cm = ((cm - 1) + 12) % 12;
            cd = d[cm];
        }
        cnt++;
    }

    return cnt;
}

int findC(int day, int month) {
    int cd = day;
    int cm = month;
    int cnt = 0;
    cd--;
    if(cd <= 0) {
        cm = ((cm - 1) + 12) % 12;
        cd = d[cm];
    }
    while(1) {
        if(cd == 27 and cm == 9) break;
        cd--;
        if(cd <= 0) {
            cm = ((cm - 1) + 12) % 12;
            cd = d[cm];
        }
        cnt++;
    }
    return cnt;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        scanf("%d-%d", &x,&y);
        x--;
        cal[y][x] = 1;
    }

    int ans = 0;
    int a1 = -1;
    int a2 = -1;
    int cl = 1e9;
    for (int i = 0; i < 12; ++i) {
        for (int j = 1; j <= d[i]; ++j) {
            int days = find(j,i);
            if(days > ans) {
                ans = days;
                a1 = j;
                a2 = i;
                cl = findC(j,i);
            }
            else if(days == ans) {
                int cur = findC(j,i);
                if(cur < cl) {
                    cl = cur;
                    a1 = j;
                    a2 = i;
                }
            }

        }
    }
    printf("%02d-%02d\n", a2 + 1, a1);
    return 0;
}

