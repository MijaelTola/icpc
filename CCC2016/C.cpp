#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define lowbit(x) (((x) ^ (x-1)) & (x))
typedef complex<long double> Complex;

void trim(vector<int>& a)
{
    while (a.size() > 0 && a.back() == 0) a.pop_back();
}

void addTo(vector<int>& a, const vector<int>& b, int k)
{
    if (a.size() < b.size() + k) a.resize(b.size() + k);
    for (int i = 0; i < (int)b.size(); i++) a[i+k] += b[i];
}

// a = a + b
void addTo(vector<int>& a, const vector<int>& b)
{
    addTo(a, b, 0);
}


// a = a - b
// a must be greater than b
void subFrom(vector<int>& a, const vector<int>& b)
{
    for (int i = 0; i <(int) b.size(); i++) a[i] -= b[i];
}

// c = a * b
vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i = 0; i <(int) a.size(); i++) {
        for (int j = 0; j <(int) b.size(); j++) {
            c[i+j] += a[i] * b[j];
        }
    }
    trim(c);
    return c;
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
    int alen = a.size();
    int blen = b.size();
    if (alen == 0 || blen == 0) return vector<int>();
    if (alen < blen) return karatsuba(b, a);
    if (alen < 50) return multiply(a, b);

    int half = alen / 2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(blen, half));
    vector<int> b1(b.begin() + min<int>(blen, half), b.end());

    vector<int> z0 = karatsuba(a0, b0);
    vector<int> z2 = karatsuba(a1, b1);
    addTo(a0, a1);
    addTo(b0, b1);
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> res;
    addTo(res, z0);
    addTo(res, z1, half);
    addTo(res, z2, half + half);
    
    trim(res);
    return res;
}
void FFT(vector<Complex> &A, int s){
    int n = A.size();
    int p = __builtin_ctz(n);
    
    vector<Complex> a = A;
    
    for(int i = 0;i<n;++i){
        int rev = 0;
        for(int j = 0;j<p;++j){
            rev <<= 1;
            rev |= ((i >> j) & 1);
        }
        A[i] = a[rev];
    }
    
    Complex w,wn;
    
    for(int i = 1;i<=p;++i){
        int M = (1<<i), K = (M>>1);
        wn = Complex(cos(s*2.0*M_PI/(double)M), sin(s*2.0*M_PI/(double)M));
        
        for(int j = 0;j<n;j += M){
            w = Complex(1.0, 0.0);
            for(int l = j;l<K+j;++l){
                Complex t = w;
                t *= A[l + K];
                Complex u = A[l];
                A[l] += t;
                u -= t;
                A[l + K] = u;
                w *= wn;
            }
        }
    }
    
    if(s==-1){
        for(int i = 0;i<n;++i)
            A[i] /= (double)n;
    }
}

vector<Complex> FFT_Multiply(vector<Complex> &P, vector<Complex> &Q){
    int n = P.size()+Q.size();
    while(n!=lowbit(n)) n += lowbit(n);
    
    P.resize(n,0);
    Q.resize(n,0);
    
    FFT(P,1);
    FFT(Q,1);
    
    vector<Complex> R;
    for(int i=0;i<n;i++) R.push_back(P[i]*Q[i]);
    
    FFT(R,-1);
    
    return R;
}
int preA[100005],preB[100005];
vector<int> A,B,ans;
int a[1000015];
int main(){
    int p,tmp,q,k;
    scanf("%d %d",&p,&k);
    for(int i = 0; i < p; i++){
        scanf("%d",&tmp);
        if(tmp < 0){
            preA[-tmp]++;
        }else{
            preB[tmp]++;
        }
    }
    for(int i = 0; i <= 100000; i++){
        A.push_back(preA[i]);
        B.push_back(preB[i]);
    }
    ans = karatsuba(A,B);
    for(int i = 0; i < (int)ans.size(); i++)
        a[i] = round(a[i]);
    
    scanf("%d",&q);
    for(int i = 0; i < q; i++){
        scanf("%d",&tmp);
        if(a[tmp] >= k)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
