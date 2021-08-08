#include <bits/stdc++.h>

using namespace std;

class OpenAllHours {
public:
	string verify(int, vector <string>, vector <string>);
};

string OpenAllHours::verify(int N, vector <string> openingTime, vector <string> closingTime) {

    bool flag = 1;
    
    set<pair<pair<int,int>, pair<int,int> > > s;
    for (int i = 0; i < N; ++i) {
        string h = openingTime[i].substr(0,2);
        string m = openingTime[i].substr(3,2);
        int hi = stoi(h);
        int mi = stoi(m);

        h = closingTime[i].substr(0,2);
        m = closingTime[i].substr(3,2);
        int hf = stoi(h);
        int mf = stoi(m);
        
        while(true) {
            if(hi == hf and mi ==mf) break;
            int l = hi, r = mi;
            mi++;
            mi %= 60;
            if(mi == 0) {
                hi++;
                hi %= 24;
            }
            s.insert({{l,r},{hi,mi}});
        }
    }

    for (int i = 0; i < 24; ++i) {
        for (int j = 0; j < 60; ++j) {

            int dm = (j + 1) % 60;
            int dh = i;
            if(dm == 0) dh = (i + 1) % 24;
            flag &= s.count({{i,j},{dh, dm}});
        }
    }
    if(flag) return "correct";
    return "incorrect";
}


double test0() {
	int p0 = 2;
	string t1[] = {"04:47","16:47"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"16:47","04:47"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	OpenAllHours * obj = new OpenAllHours();
	clock_t start = clock();
	string my_answer = obj->verify(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "correct";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 3;
	string t1[] = {"03:00", "18:30", "08:59"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"09:00", "04:15", "19:01"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	OpenAllHours * obj = new OpenAllHours();
	clock_t start = clock();
	string my_answer = obj->verify(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "correct";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 3;
	string t1[] = {"03:47", "03:48", "03:49"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"03:44", "03:45", "03:46"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	OpenAllHours * obj = new OpenAllHours();
	clock_t start = clock();
	string my_answer = obj->verify(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "incorrect";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 1;
	string t1[] = {"05:00"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"04:59"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	OpenAllHours * obj = new OpenAllHours();
	clock_t start = clock();
	string my_answer = obj->verify(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "incorrect";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 6;
	string t1[] = {"01:08", "12:46", "23:28", "20:30", "19:02", "06:41"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"05:56", "18:53", "02:29", "23:26", "23:57", "08:44"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	OpenAllHours * obj = new OpenAllHours();
	clock_t start = clock();
	string my_answer = obj->verify(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "incorrect";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 7;
	string t1[] = {"01:12", "11:23", "12:23", "13:05", "18:26", "08:37", "22:08"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"03:21", "13:04", "22:16", "21:46", "08:19", "10:17", "13:01"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	OpenAllHours * obj = new OpenAllHours();
	clock_t start = clock();
	string my_answer = obj->verify(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "correct";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
