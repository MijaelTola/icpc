#include <bits/stdc++.h>

using namespace std;

class CapriciousSorting {
public:
	int count(vector <int>);
};

int CapriciousSorting::count(vector <int> num) {
	
    int mn = 0;
    int ans = 1;
    for (int i = 31; i >= 0; i--) {
        int mx = 0;    
        int mxx = 0;
        bool flag = 0;
        int mn = 1;
        for (int j = 0; j < (int)num.size(); ++j) {
            int cur = !!(num[j] & (1 << i));
            mx = max(mx, cur);
            mn = min(mx, cur);
            mxx = max(mxx, num[i]);
            if(j and num[j] <= mx)
                flag |= cur < mx;
        }
        
        cout << i << ": " << mx << " " << mn << "\n";
        if(!flag and mx == mn) {
            cout << i << " gg\n";
            ans <<= 1;
        }
    }

    for (int i = 1; i < (int)num.size(); ++i)
        if(num[i] <= num[i - 1]) return 0;

    cout << mn << "\n";
    //exit(0);
    return ans;
}



double test0() {
	int t0[] = {0, 1, 2, 3, 4, 5, 6, 7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	CapriciousSorting * obj = new CapriciousSorting();
	clock_t start = clock();
	int my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 134217728;
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
	int t0[] = {7, 6, 5, 4, 3, 2, 1, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	CapriciousSorting * obj = new CapriciousSorting();
	clock_t start = clock();
	int my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 134217728;
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
	int t0[] = {47, 47, 42};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	CapriciousSorting * obj = new CapriciousSorting();
	clock_t start = clock();
	int my_answer = obj->count(p0);
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
double test3() {
	int t0[] = {84, 94, 68, 72, 96, 31, 2, 57};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	CapriciousSorting * obj = new CapriciousSorting();
	clock_t start = clock();
	int my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 67108864;
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
	exit(0);
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
