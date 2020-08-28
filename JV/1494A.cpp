#include <bits/stdc++.h>

using namespace std;


int fibo(int j) {
   int a = 1;
   int b = 0;
   int c = -1;
   for (int i = 0; i < j; ++i) {
        c = a + b;
        a = b;
        b = c;
   }
   return c;
}

bool esPrimo(int x) {
    for (int i = 2; i <= x / 2; ++i) 
        if(x % i == 0) return false;
    return true;
}
int primo(int j) {
    int c = 0;
    int p = 2;
    while(c < j) {
        if(esPrimo(p) == true)  c++;
        p++;
    }
    return p - 1;
}

void imprimir(int respuesta) {
    cout << respuesta << "\n";
}

int main(){
    int n,x;
    cin >> n >> x;
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        double ifibo = fibo(i);
        double iprimo = primo(i);
        sum += (ifibo / (iprimo * x));
    }
    imprimir(sum);
    return 0;
}

