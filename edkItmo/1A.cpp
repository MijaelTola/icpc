#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n", (a + b));
    return 0;
}

