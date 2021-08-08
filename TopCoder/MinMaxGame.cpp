#include <bits/stdc++.h>

using namespace std;

class MinMaxGame {
public:
	int lastNumber(vector <int>);
};

int MinMaxGame::lastNumber(vector <int> A) {
	
    deque<int> q;

    sort(A.begin(), A.end());

    for (int i = 0; i < (int)A.size(); ++i)
        q.push_back(A[i]);

    int turno = 1;
    while(q.size() > 1) {
        if(turno) {
            int a = q.front();
            q.pop_front();
            q.pop_front();
            q.push_front(a);
        } else {
            int a = q.back();
            q.pop_back();
            q.pop_front();
            q.push_back(a);
        }

        for (auto x: q)
            cout << x << " ";
        cout << " test\n";
        turno = 1 - turno;
    }

    //1 4 5 5 6 A
    //1 5 5 6 B
    //5 5 6 A
    //5 6 b
    //5

    return q.back();
}


double test0() {
	int t0[] = {3, 2, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MinMaxGame * obj = new MinMaxGame();
	clock_t start = clock();
	int my_answer = obj->lastNumber(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
	int t0[] = {2, 5, 3, 7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MinMaxGame * obj = new MinMaxGame();
	clock_t start = clock();
	int my_answer = obj->lastNumber(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	int t0[] = {4, 5, 1, 6, 5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MinMaxGame * obj = new MinMaxGame();
	clock_t start = clock();
	int my_answer = obj->lastNumber(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
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
