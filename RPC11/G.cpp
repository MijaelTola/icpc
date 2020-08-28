#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>
#include <string> 
#include <sstream>
#include <cstdlib>

using namespace std;

typedef long long ll;

int negros[510][510];
int blancos[510][510];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    memset(negros,0,sizeof negros);
    memset(blancos,0,sizeof blancos);
    int n,p;
    cin >> n >> p;
    for (int i = 0; i < p; ++i){
        int x,y;cin >> x >> y;
        negros[x-1][y-1] = 1;
    }
    for (int i = 0; i < p; ++i){
        int x,y; cin >> x >> y;
        blancos[x-1][y-1] = 1;
    }
    
    for(int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            if(i > 0) negros[i][j] += negros[i-1][j];
            if(j > 0) negros[i][j] += negros[i][j-1];
            if(i > 0 and j > 0) negros[i][j] -= negros[i-1][j-1];
        }
        
    for(int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            if(i > 0) blancos[i][j] += blancos[i-1][j];
            if(j > 0) blancos[i][j] += blancos[i][j-1];
            if(i > 0 and j > 0) blancos[i][j] -= blancos[i-1][j-1];
        }
    
    int ans1 = p;
    int ans2 = p;
    
    for (int k = 2; k < n; ++k){
        for (int i = 0; i <= n-k; i++){
            for (int j = 0; j <= n-k; j++){
                int sumb = blancos[i+k-1][j+k-1];
                int sumn =  negros[i+k-1][j+k-1];
                if(i > 0){
                    sumn -= negros[i-1][j+k-1];
                    sumb -= blancos[i-1][j+k-1];
                }
                if(j > 0){
                    sumn -= negros[i+k-1][j-1];
                    sumb -= blancos[i+k-1][j-1];
                }

                if(i > 0 and j > 0){
                    sumn += negros[i-1][j-1];
                    sumb += blancos[i-1][j-1];
                }
                if(sumb == 0 and sumn > 0) ans1++;
                if(sumb > 0 and sumn == 0) ans2++;
            }
        }
    }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}

