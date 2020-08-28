#include <bits/stdc++.h>


using namespace std;

const int mod = 1812447359;

class SuffixDecomposition {
    public:
        long long findTotalFun(vector <int>, int, int, int, int, int, int, int);
};

long long st[2 * 200010];
int m = 200010;
void update(int pos,int value){
    for (st[pos+=m]= value; pos > 1; pos>>=1)
        st[pos>>1] = min(st[pos], st[pos^1]);
}
// interval[l,r)
long long query(int l,int r){
    long long ans = LLONG_MAX;;
    r++;
    for (l+=m,r+=m;l<r;l>>=1,r>>=1){
        if(l&1) ans = min(ans, st[l++]);
        if(r&1) ans = min(ans, st[--r]);
    }
    return ans;
}

long long SuffixDecomposition::findTotalFun(vector <int> p, int A0, int X, int Y, int B0, int X1, int Y1, int n) {

    memset(st, 60, sizeof st);
    vector<long long> a,b,s,cnt(n + 10, 0);

    for (int x: p)
        s.push_back(x);
    a.push_back(A0);

    for (int i = 1; i < n; i++)
        a.push_back(((a.back() * X) % mod + Y) % mod);

    b.push_back(B0);
    for (int i = 1; i < n; i++)
        b.push_back(((b.back() * X1) % mod + Y1) % mod);

    for (int i = p.size(); i < n; ++i) {
        s.push_back(max(a[i],b[i]));
    }

    for (int x: s)
        cout << x << " ";
    cout << "\n";
    //exit(0);
    for (int i = 0; i < n; ++i)
        update(i, s[i]);
    long long mx = 0;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, s[i]);
        int mn = query(i + 1, n - 1);
        cout << mx << " " << mn << "\n";
        if(mx <= mn) {
            cout << " cac\n";
            cnt[i] = 1;
            mx = s[i + 1];
        }
    }
//    for (int i = n - 1; i >= 0; i--) 
        //cnt[i] += cnt[i + 1];

    for (int i = 0; i < n; ++i)
        cout << cnt[i] << " ";
    cout << "\n";


    long long ans = 0;

    for (int i = 0; i < n; ++i)
        ans += cnt[i] + 1;

    //cout << ans << "\n";
    //exit(0);
    return ans;
}


double test0() {
    int t0[] = {3, 9, 5};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    int p4 = 0;
    int p5 = 0;
    int p6 = 0;
    int p7 = 3;
    SuffixDecomposition * obj = new SuffixDecomposition();
    clock_t start = clock();
    long long my_answer = obj->findTotalFun(p0, p1, p2, p3, p4, p5, p6, p7);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p8 = 4LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p8 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p8 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1() {
    int t0[] = {10};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 1;
    int p2 = 2;
    int p3 = 2;
    int p4 = 3;
    int p5 = 1;
    int p6 = 2;
    int p7 = 4;
    SuffixDecomposition * obj = new SuffixDecomposition();
    clock_t start = clock();
    long long my_answer = obj->findTotalFun(p0, p1, p2, p3, p4, p5, p6, p7);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p8 = 8LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p8 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p8 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2() {
    vector <int> p0;
    int p1 = 1000001;
    int p2 = 1000001;
    int p3 = 1000001;
    int p4 = 5000001;
    int p5 = 5000001;
    int p6 = 5000001;
    int p7 = 4;
    SuffixDecomposition * obj = new SuffixDecomposition();
    clock_t start = clock();
    long long my_answer = obj->findTotalFun(p0, p1, p2, p3, p4, p5, p6, p7);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p8 = 6LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p8 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p8 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3() {
    vector <int> p0;
    int p1 = 1812447358;
    int p2 = 1812447358;
    int p3 = 1812447358;
    int p4 = 42524;
    int p5 = 2565262;
    int p6 = 2676642;
    int p7 = 6;
    SuffixDecomposition * obj = new SuffixDecomposition();
    clock_t start = clock();
    long long my_answer = obj->findTotalFun(p0, p1, p2, p3, p4, p5, p6, p7);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p8 = 7LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p8 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p8 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test4() {
    vector <int> p0;
    int p1 = 1010;
    int p2 = 2010;
    int p3 = 3010;
    int p4 = 900010;
    int p5 = 9000;
    int p6 = 76540;
    int p7 = 8;
    SuffixDecomposition * obj = new SuffixDecomposition();
    clock_t start = clock();
    long long my_answer = obj->findTotalFun(p0, p1, p2, p3, p4, p5, p6, p7);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p8 = 10LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p8 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p8 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}

int main() {
    test1();
}
/*
int main() {
    int time;
    bool errors = false;

    time = test0();
    if (time < 0)
        errors = true;

    time = test1();
    if (time < 0)
        errors = true;

    time = test2();
    if (time < 0)
        errors = true;

    time = test3();
    if (time < 0)
        errors = true;

    time = test4();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}
*/
//Powered by [KawigiEdit] 2.0!
