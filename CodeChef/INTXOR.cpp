#include <bits/stdc++.h>

using namespace std;

int v[50010];
int Right;

int solve(int n) {
    int i,j,k,x, cnt = 0;
    i = 1, j = 2, k = 3; 
    while(i <= n) i += 3; 
    i -= 3;
    while(j <= n and j <= i) j += 3; 
    j -= 3;
    while(k <= n and k <= i) k += 3; 
    k -= 3;
    for (int p = 1; p <= n - 2; p++) {
        cnt++;
        int a = p;
        int b = p + 1;
        int c = p + 2;
        printf("1 %d %d %d\n", a, b, c);
        fflush(stdout);
        scanf("%d", &x);
        v[p] = x;
        if(a == i or b == i or c == i) break;
    }

    printf("1 %d %d %d\n", 1, i, 2);
    fflush(stdout);
    int a1102 = 0, a1109 = 0;
    scanf("%d", &a1102);
    printf("1 %d %d %d\n", 1, i, k);
    fflush(stdout);
    scanf("%d", &a1109);

    int a = 0, b = 0, c = 0, d = 0;

    for (int i = 1; i <= cnt; i += 3) 
        a ^= v[i];

    for (int i = 2; i <= cnt; i += 3) 
        b ^= v[i];

    for (int i = 3; i <= cnt; i += 3) 
        c ^= v[i];

    for (int i = 4; i < cnt; i += 3) 
        d ^= v[i];

    int a110 = a ^ b;
    int a39 = c ^ d;
    int a2 = a110 ^ a1102;
    int a9 = a1109 ^ a110;
    int a3 = a9 ^ a39;
    int a1 = v[1] ^ a2 ^ a3;
    vector<int> ans;
    ans.push_back(a1);
    ans.push_back(a2);
    ans.push_back(a3);

    for (int i = 2; i <= cnt; ++i) {
        int sz = ans.size();
        ans.push_back(v[i] ^ ans[sz - 1] ^ ans[sz - 2]);
    }

    printf("2 ");
    for (int i = 0; i < n; ++i) 
        printf("%d ", ans[i]);
    printf("\n");
    fflush(stdout);
    scanf("%d", &Right);
    return Right;
}

int solve2(int n) {
    
    int p = 1,x;
    for (int i = 1; i <= n - 2; i++) {
        printf("1 %d %d %d\n",p, p + 1, p + 2);
        fflush(stdout);
        scanf("%d", &x);
        v[i] = x;
        p++;
    }
    
    int a178 = 0, a281 = 0;
    printf("1 %d %d %d\n", 1, n - 1, n);
    fflush(stdout);
    scanf("%d", &a178);
    printf("1 %d %d %d\n", 2, n, 1);
    fflush(stdout);
    scanf("%d", &a281);

    int a = 0, b = 0, c = 0;
    for (int i = 1; i <= n - 2; i += 3) 
        a ^= v[i];
    for (int i = 2; i <= n - 2; i += 3)
        b ^= v[i];
    for (int i = 3; i <= n - 2; i += 3)
        c ^= v[i];

    int a17 = a ^ b;
    int a28 = b ^ c;
    int a8 = a17 ^ a178;
    int a2 = a8 ^ a28;
    int a1 = a28 ^ a281;
    
    vector<int> ans;
    ans.push_back(a1);
    ans.push_back(a2);
    for (int i = 1; i <= n - 2; i++) {
        int sz = ans.size();
        ans.push_back(v[i] ^ ans[sz - 1] ^ ans[sz - 2]);
    }
    
    printf("2 ");
    for (int i = 0; i < n; ++i) 
        printf("%d ", ans[i]);
    printf("\n");
    fflush(stdout);
        
    scanf("%d", &Right);
    return Right;
}

int solve3(int n) {
    int p = 1,x;
    for (int i = 1; i <= n - 4; ++i) {
        printf("1 %d %d %d\n",p, p + 1, p + 2);
        fflush(stdout);
        scanf("%d", &x);
        v[i] = x;
        p++;
    }
    int a178 = 0, a179 = 0;
    printf("1 %d %d %d\n",1, n - 2, n - 1);
    fflush(stdout);
    scanf("%d", &a178);
    printf("1 %d %d %d\n",1, n - 2, n);
    fflush(stdout);
    scanf("%d", &a179);

    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 1; i <= n - 4; i += 3) 
        a ^= v[i];

    for (int i = 2; i <= n - 4; i += 3)
        b ^= v[i];

    for (int i = 3; i <= n - 4; i += 3)
        c ^= v[i];
    
    for (int i = 4; i <= n - 4; i += 3)
        d ^= v[i];

    int a17 = a ^ b;
    int a36 = c ^ d;
    int a8 = a17 ^ a178;
    int a9 = a17 ^ a179;
    int a892 = 0, a896 = 0;
    printf("1 %d %d %d\n",n - 1, n, 2);
    fflush(stdout);
    scanf("%d", &a892);
    printf("1 %d %d %d\n",n - 1, n, n - 3);
    fflush(stdout);
    scanf("%d", &a896);

    int a2 = a892 ^ a8 ^ a9;
    int a6 = a896 ^ a8 ^ a9;
    int a3 = a36 ^ a6;

    int a1 = v[1] ^ a2 ^ a3;
    vector<int> ans;
    ans.push_back(a1);
    ans.push_back(a2);
    ans.push_back(a3);
    
    for (int i = 2; i <= n - 4; i++) {
        int sz = ans.size();
        ans.push_back(v[i] ^ ans[sz - 1] ^ ans[sz - 2]);
    }
    ans.push_back(a8);
    ans.push_back(a9);
    printf("2 ");
    for (int i = 0; i < n; ++i) 
        printf("%d ", ans[i]);
    printf("\n");
    fflush(stdout);
    scanf("%d", &Right);
    return Right;
}

int main() {
    int t; 
    scanf("%d", &t);
    while(t--) {
        memset(v, 0, sizeof v);
        int n,i,j,k,x, cnt = 0;
        scanf("%d", &n);
        int ans;
        if(n % 3 == 1) ans = solve(n);      
        if(n % 3 == 2) ans = solve2(n);
        if(n % 3 == 0) ans = solve3(n);
        assert(ans != -1);
    }

    return 0;
}


