#include <bits/stdc++.h>

using namespace std;

class GoldMining {
public:
	long long maxProfit(long long, long long, long long);
};

long long GoldMining::maxProfit(long long goldInGround, long long miningTime, long long hiringCost) {
	
    long double workers = 1;
    long double current = 0;

    for (int i = 1; i <= miningTime; ++i) {
        //cout << current << " " << workers << endl;
        long double val = min(workers, (long double) goldInGround);
        current += val;
        goldInGround -= val;
        
        long double left = miningTime - i;
        long double win = current + min((long double) goldInGround, left * workers);
        long double a = 0, b = 1e11;
        
        while(b - a > 1) {
            long double mid = (long long)((a + b) / 2);
            long double cost = mid * hiringCost;
            long double nwin = current + min((long double)goldInGround, left * (workers + mid)) - cost;
            if(nwin >= win) a = mid;
            else b = mid;
        }
        workers += a;
        current -= a * hiringCost;
    }

    return current;
}


double test0() {
	long long p0 = 470000LL;
	long long p1 = 1000000LL;
	long long p2 = 50LL;
	GoldMining * obj = new GoldMining();
	clock_t start = clock();
	long long my_answer = obj->maxProfit(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 470000LL;
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
	long long p0 = 470000LL;
	long long p1 = 100000LL;
	long long p2 = 1234567890123456LL;
	GoldMining * obj = new GoldMining();
	clock_t start = clock();
	long long my_answer = obj->maxProfit(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 100000LL;
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
	long long p0 = 470000LL;
	long long p1 = 100000LL;
	long long p2 = 57000LL;
	GoldMining * obj = new GoldMining();
	clock_t start = clock();
	long long my_answer = obj->maxProfit(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 100000LL;
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
	long long p0 = 470000LL;
	long long p1 = 100000LL;
	long long p2 = 42000LL;
	GoldMining * obj = new GoldMining();
	clock_t start = clock();
	long long my_answer = obj->maxProfit(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 116000LL;
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
	long long p0 = 567890LL;
	long long p1 = 4LL;
	long long p2 = 1LL;
	GoldMining * obj = new GoldMining();
	clock_t start = clock();
	long long my_answer = obj->maxProfit(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 8LL;
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
double test5() {
	long long p0 = 234567LL;
	long long p1 = 47LL;
	long long p2 = 10LL;
	GoldMining * obj = new GoldMining();
	clock_t start = clock();
	long long my_answer = obj->maxProfit(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 215LL;
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
double test6() {
	long long p0 = 300LL;
	long long p1 = 47LL;
	long long p2 = 10LL;
	GoldMining * obj = new GoldMining();
	clock_t start = clock();
	long long my_answer = obj->maxProfit(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 190LL;
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
double test7() {
	long long p0 = 987654321098765432LL;
	long long p1 = 100LL;
	long long p2 = 3LL;
	GoldMining * obj = new GoldMining();
	clock_t start = clock();
	long long my_answer = obj->maxProfit(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 2731288513472LL;
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
	
    /**
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
	
     */
	time = test4();
	if (time < 0)
		errors = true;
    exit(0);
	
	time = test5();
	if (time < 0)
		errors = true;
	
	time = test6();
	if (time < 0)
		errors = true;
	
	time = test7();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
