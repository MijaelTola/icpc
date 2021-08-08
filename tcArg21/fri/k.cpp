#include <bits/stdc++.h>

using namespace std;

int p[100010];
void init() {for (int i = 0; i < 100010; ++i) p[i] = i;}
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]);}
void merge(int x, int y) { p[find(y)] = p[find(x)];}

int main() {

    return 0;
}

