#include <bits/stdc++.h>

using namespace std;

class HandsShaking {
public:
	long long countPerfect(int);
};

long long dp[55][55];
long long f(int l, int r) {
    if(r - l <= 1) return 1;

    long long &ans = dp[l][r];
    if(ans != -1) return ans;
    ans = 0;

    auto check = [] (int x, int y) {
        return ((y - x) + 1) % 2 == 0;
    };

    for (int i = l + 1; i <= r; ++i) 
        if(check(l, i)) 
            ans += f(l + 1, i - 1) * f(i + 1, r);

    return ans;
}

long long HandsShaking::countPerfect(int n) {
    memset(dp, -1, sizeof dp);
    return f(0, n - 1);
}


double test0() {
	int p0 = 2;
	HandsShaking * obj = new HandsShaking();
	clock_t start = clock();
	long long my_answer = obj->countPerfect(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 1LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 4;
	HandsShaking * obj = new HandsShaking();
	clock_t start = clock();
	long long my_answer = obj->countPerfect(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 2LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 8;
	HandsShaking * obj = new HandsShaking();
	clock_t start = clock();
	long long my_answer = obj->countPerfect(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 14LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
