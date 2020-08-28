#include <bits/stdc++.h>

using namespace std;

class EllysConjectureDiv2 {
    public:
        long long getSum(int, int);
};

long long get (long long x) {
    if(x == 0) return 0LL;
    if(x == 1) return 1LL;
    if(x == 2) return 3LL;
    if(x == 3) return 6LL;
    if(x == 4) return 10LL;
    if(x == 5) return 14LL;
    long long dv = x / 3;
    long long left = x - dv;
    long long ans = 6 * dv + 4 * left - 8;
    return ans;
}

long long EllysConjectureDiv2::getSum(int L, int R) {
    long long l = get(L - 1);
    long long r = get(R);
    return r - l;
}


double test0() {
    int p0 = 13;
    int p1 = 17;
    EllysConjectureDiv2 * obj = new EllysConjectureDiv2();
    clock_t start = clock();
    long long my_answer = obj->getSum(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p2 = 22LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1() {
    int p0 = 42;
    int p1 = 1337;
    EllysConjectureDiv2 * obj = new EllysConjectureDiv2();
    clock_t start = clock();
    long long my_answer = obj->getSum(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p2 = 6048LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2() {
    int p0 = 12345;
    int p1 = 67890;
    EllysConjectureDiv2 * obj = new EllysConjectureDiv2();
    clock_t start = clock();
    long long my_answer = obj->getSum(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p2 = 259216LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3() {
    int p0 = 42666;
    int p1 = 133742;
    EllysConjectureDiv2 * obj = new EllysConjectureDiv2();
    clock_t start = clock();
    long long my_answer = obj->getSum(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p2 = 425026LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test4() {
    int p0 = 123456789;
    int p1 = 987654321;
    EllysConjectureDiv2 * obj = new EllysConjectureDiv2();
    clock_t start = clock();
    long long my_answer = obj->getSum(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p2 = 4032921822LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}

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
//Powered by [KawigiEdit] 2.0!
