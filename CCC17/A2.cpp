#include <bits/stdc++.h>
using namespace std;
int n;
double x[3010],y[3010];
string s;
int main(){
    cin >> n;
    for (int i = 0;i < n;i++) {
        scanf("%Lf",x + i);
        scanf("%Lf",y + i);
        x[i] = log(x[i]);
        y[i] = log(y[i]);
    }
    
    double X,Y,M,S;
    X = Y = M = S = 0.0;
    for (int i = 0; i < n; ++i){
        X += x[i]; 
        Y += y[i];
        M += x[i] * y[i];
        S += x[i] * x[i];
    }

    double b = (n * M - X*Y) / (n * S - X*X);
    double a = exp((M - b * S) / X);

    
    int t;  
    cin >> t >> s;
    cout.precision(2);
    cout << fixed  <<s << " " << (double)a * pow(t,b) << "\n";

    return 0;
}
