#include <iostream>

using namespace std;

int main(){
    
    for (int k = 0; k < 100; ++k) {
        
        int n = rand() % 100;
        if(n == 0) continue;
        cout << n << "\n";
        for (int i = 0; i < n; ++i) {
            cout << rand() % 2 << " ";
        }
        cout << "\n";
    }
    cout << 100 << "\n";
    for (int i = 0; i < 100; ++i)
        cout << 0 << " ";
    cout << "\n";
    return 0;
}
