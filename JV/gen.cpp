#include <iostream>
#include <set>

using namespace std;

int main(){
    
    int n = 100;
    int k = 1e5;

    set<int> s;
    
    while((int)s.size() < n) {
        s.insert((rand() % k) + 1);
    }
    
    cout << n << " " << k << "\n";
    
    for (auto x: s)
        cout << x << " ";
    cout << "\n";

    return 0;
}
