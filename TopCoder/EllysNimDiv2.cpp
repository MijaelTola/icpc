#include <bits/stdc++.h>

using namespace std;

class EllysNimDiv2 {
public:
	int getMin(vector <int>);
};

int EllysNimDiv2::getMin(vector <int> A) {
	
    int ans = 0;

    for (int x: A)
        ans ^= x;
        
    int a = 1e9;
    for (int x: A) {
        if(x >= ans) continue;
        int no = x ^ ans;
        if(no > x) {
            a = min(a, no - x);
        }
            
    }
    return a;
}


double test0() {
	int t0[] = {42, 13, 123, 55, 666, 17};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysNimDiv2 * obj = new EllysNimDiv2();
	clock_t start = clock();
	int my_answer = obj->getMin(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 480;
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
	int t0[] = {1, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysNimDiv2 * obj = new EllysNimDiv2();
	clock_t start = clock();
	int my_answer = obj->getMin(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
	int t0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysNimDiv2 * obj = new EllysNimDiv2();
	clock_t start = clock();
	int my_answer = obj->getMin(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
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
double test3() {
	int t0[] = {371, 740, 211, 798, 82, 385, 979, 389, 31, 667, 541, 561, 471};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysNimDiv2 * obj = new EllysNimDiv2();
	clock_t start = clock();
	int my_answer = obj->getMin(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 42;
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
double test4() {
	int t0[] = {769, 727, 657, 924, 879, 674, 652, 995, 947, 896, 869, 553, 954, 974, 681, 768, 913};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysNimDiv2 * obj = new EllysNimDiv2();
	clock_t start = clock();
	int my_answer = obj->getMin(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 666;
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
double test5() {
	int t0[] = {543, 230, 421, 415, 271, 962, 677, 373, 951, 114, 379, 15, 211, 955,
 66,  573, 982, 296, 730, 591, 750, 877, 224, 186, 398, 84, 542, 770,
 288, 78,  373, 417, 476, 968, 564, 565, 740, 377, 633, 287, 111, 823};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysNimDiv2 * obj = new EllysNimDiv2();
	clock_t start = clock();
	int my_answer = obj->getMin(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 44;
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
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
