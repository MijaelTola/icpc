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
#include <unordered_set>
#include <unordered_map>
#include <cstdio>

using namespace std;

int i,j,k,n;
double A[25][25],c,x[15],sum=0.0;

void print(){
    for (i=1; i <= n; ++i){
        for (j=1; j<=n+1; ++j) cout<< A[i][j] << " ";
        cout << endl;
    }
}
void build(){
    for(j=1; j<=n; j++){
        for(i=1; i<=n; i++){
            if(i>j){
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                    A[i][k]=A[i][k]-c*A[j][k];
            }
        }
    }
}
int main(){
    cin >> n;
    
    for(i=1; i<=n; i++)
        for(j=1; j<= n+1; j++) 
            cin >> A[i][j];
    
    build();
    
    x[n]=A[n][n+1]/A[n][n];
    
    for(i=n-1; i>=1; i--){
        sum=0;
        for(j=i+1; j<=n; j++)
            sum += A[i][j]*x[j];
        x[i]=(A[i][n+1]-sum)/A[i][i];
    }
    cout.precision(3);
    for(i=1; i<=n; i++)
        cout << fixed << x[i] << " ";
    
    return 0;
}
