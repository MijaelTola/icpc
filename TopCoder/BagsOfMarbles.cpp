#include <vector>
#include <bits/stdc++.h>

using namespace std;

class BagsOfMarbles {
public:
	int removeFewest(int, int, int, int, int, int);
};

int BagsOfMarbles::removeFewest(int desired, int bagSize, int noWhiteBags, int noBlackBags, int someWhiteBags, int someBlackBags) {
    if(noBlackBags * bagSize >= desired) return desired;

    noWhiteBags *= desired;
    int total = (noBlackBags * bagSize+ someWhiteBags + someBlackBags);
    if(total >= desired) return total;

    return -1;
}


double test0() {
	int p0 = 5;
	int p1 = 10;
	int p2 = 0;
	int p3 = 1;
	int p4 = 0;
	int p5 = 0;
	BagsOfMarbles * obj = new BagsOfMarbles();
	clock_t start = clock();
	int my_answer = obj->removeFewest(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 2;
	int p1 = 10;
	int p2 = 2;
	int p3 = 0;
	int p4 = 1;
	int p5 = 0;
	BagsOfMarbles * obj = new BagsOfMarbles();
	clock_t start = clock();
	int my_answer = obj->removeFewest(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 51;
	int p1 = 7;
	int p2 = 7;
	int p3 = 7;
	int p4 = 7;
	int p5 = 7;
	BagsOfMarbles * obj = new BagsOfMarbles();
	clock_t start = clock();
	int my_answer = obj->removeFewest(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 63;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
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
