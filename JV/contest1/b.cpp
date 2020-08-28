#include <bits/stdc++.h>

using namespace std;

long long val(char c) { 
    if (c >= '0' && c <= '9') 
        return (long long)c - '0'; 
    else
        return (long long)c - 'A' + 10; 
}

char reVal(int num) { 
    if (num >= 0 && num <= 9) 
        return (char)(num + '0'); 
    else
        return (char)(num - 10 + 'A'); 
} 
long long toDeci(string str, int base) { 
    int len = str.size(); 
    long long power = 1;
    long long num = 0;
    int i; 
    for (i = len - 1; i >= 0; i--) { 
        num += val(str[i]) * power; 
        power = power * base; 
    } 
    return num; 
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    int n;
    while(cin >> n >> s) {
    long long ans = 0;
    string cur = "";
    char last = '+';
    for (char x: s) {
        if(x != '+' and x != '-') {
            cur += x;
        } else {
            if(last == '+')ans += toDeci(cur,n);
            if(last == '-')ans -= toDeci(cur,n);
            last = x;
            cur = "";
        }
    }
    
    if(last == '+')ans += toDeci(cur,n);
    if(last == '-')ans -= toDeci(cur,n);
    if(ans == 0) {
        cout << ans << "\n";
        continue;
    }
    string a = "";
    bool flag = ans > 0;
    ans = abs(ans);
    while(ans > 0) {
        a += reVal(ans % n);
        ans /= n;
    }
    reverse(a.begin(), a.end());
    if(!flag) cout << "-";
    cout << a << "\n";
    }
    return 0;
}

