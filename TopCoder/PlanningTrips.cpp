#include <bits/stdc++.h>

using namespace std;

class PlanningTrips {
public:
	int find(int, vector <int>);
};

int PlanningTrips::find(int a, vector <int> num) {

    priority_queue<long long > q;

    for (int i = 0; i < (int)num.size(); ++i) {
        q.push(-num[i]);
    }

    long long last = -1;
    long long cnt = 0;
    long long mx = 0;
    vector<long long> v;
    while(!q.empty()) {
        long long  u = -q.top();
        q.pop();
        mx = max(u, mx);
        if(u == last) cnt++;
        else {
            if(last != -1) v.push_back(u);
            last = u;
            cnt = 1;
            continue;
        }
        
        if(cnt == a) 
            q.push(-(u + 1));
        
        last = u;
    }

    if(v.size() == 1) return v.back();
    else return v.back() + 1;

}


double test0() {
	int p0 = 2;
	int t1[] = {1,1,1,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PlanningTrips * obj = new PlanningTrips();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 7;
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
	int p0 = 2;
	int t1[] = {13, 13};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PlanningTrips * obj = new PlanningTrips();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 14;
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
	int p0 = 2;
	int t1[] = {13, 0, 13};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PlanningTrips * obj = new PlanningTrips();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 15;
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
	int time = 0;
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
