#include <bits/stdc++.h>

using namespace std;

int x,y,z;
bool esPrimo(int x) {
    bool primo = 1;
    for (int i = 2; i <= x / 2; ++i) {
        if(x % i == 0) {
            primo = 0;
            break;
        }
    }
    if(primo) return 1;
    else return 0;
}

int sumarTresNumeros(int a, int b, int c) {
    int x = a + b + c;
    return x;
}

void imprimir(int respuesta) {
    cout << respuesta << "\n";
}

int main() {
    cin >> x >> y >> z;
    int respuesta = sumarTresNumeros(x,y,z);
    imprimir(respuesta);
 /*   int n;
    scanf("%d", &n);

    int c = 0;
    int number = 2;
    while(c < n) {
        bool primo = esPrimo(number);
        if(primo) {
            printf("%d ", number);
            c++;
        }
        number++;
    }
*/
    return 0;
}

