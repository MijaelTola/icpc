#include <bits/stdc++.h>

using namespace std;

class JumpAcrossTheRiver {
public:
	long long minLength(int, int, int);
};


bool can(long long l, int n, int m, int j) {
    long long current = 0;
    int ans = 0;

    for (long long i = 0; i < n; ++i) {
        long long value = (1LL * i * i) % m + 1;
        //cout << i << " " << current << endl;
        if(current + value <= l) {
            current += value;
            //if(current == l) current = 0;
        } else {
            ans++;
            if(value <= l) {
                current = value;
            } else return 0;
        }
    }
    ans++;
    //cout << " cta" << ans << endl;
    return ans <= j;
}

long long JumpAcrossTheRiver::minLength(int N, int M, int J) {
	
    
    //cout << can(9, N, M, J) << endl;
    
    //exit(0);
    long long a = -1, b = 1e14;

    while(b - a > 1) {
        long long mid = (a + b) / 2;
        if(can(mid, N, M, J)) b = mid;
        else a = mid;
    }

    return b;
}


double test0() {
	int p0 = 10;
	int p1 = 1;
	int p2 = 1;
	JumpAcrossTheRiver * obj = new JumpAcrossTheRiver();
	clock_t start = clock();
	long long my_answer = obj->minLength(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 10LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 10;
	int p1 = 1;
	int p2 = 3;
	JumpAcrossTheRiver * obj = new JumpAcrossTheRiver();
	clock_t start = clock();
	long long my_answer = obj->minLength(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 4LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 10;
	int p1 = 1234567;
	int p2 = 10;
	JumpAcrossTheRiver * obj = new JumpAcrossTheRiver();
	clock_t start = clock();
	long long my_answer = obj->minLength(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 82LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 10;
	int p1 = 1234567;
	int p2 = 4;
	JumpAcrossTheRiver * obj = new JumpAcrossTheRiver();
	clock_t start = clock();
	long long my_answer = obj->minLength(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 87LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 123456;
	int p1 = 1000000007;
	int p2 = 2;
	JumpAcrossTheRiver * obj = new JumpAcrossTheRiver();
	clock_t start = clock();
	long long my_answer = obj->minLength(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 27561114912135LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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
