#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class AqaAsadiNames {
public:
	string getName(string, string, string, string);
};

string AqaAsadiNames::getName(string Dad, string Mom, string FirstChild, string Gender) {
	
    auto is = [&] (char x) {
        return x == 'A' or x == 'E' or x == 'I' or x == 'O' or x == 'U' or x == 'Y';
    };

    string ans = "";
    if(Gender[0] == 'B') {
        if(!is(FirstChild[0])) {
            int p = 0;
            while(Dad[p] != ' ') ans += Dad[p++];
            ans += " ";
            p = 0;
            while(FirstChild[p] != ' ') p++;
            p++;
            for (int i = p; i < (int)FirstChild.size(); ++i)
                ans += FirstChild[i];
        } else {
            int p = 0;
            string x = "", y = "";
            while(Dad[p] != ' ') x += Dad[p++];
            p++;
            while(p < (int)Dad.size()) y += Dad[p++];
            ans = y + " " + x;
        }
    } else {
        if(is(FirstChild[0])) {
            int p = 0;
            while(Mom[p] != ' ') ans += Mom[p++];
            ans += " ";
            p = 0;
            while(FirstChild[p] != ' ') p++;
            p++;
            for (int i = p; i < (int)FirstChild.size(); ++i)
                ans += FirstChild[i];
        } else {
            int p = 0;
            string x = "", y = "";
            while(Mom[p] != ' ') x += Mom[p++];
            p++;
            while(p < (int)Mom.size()) y += Mom[p++];
            ans = y + " " + x;
        }
    }

    return ans;
}


double test0() {
	string p0 = "Mohammad Reza";
	string p1 = "Yasaman Sadat";
	string p2 = "Baqer Ali";
	string p3 = "Boy";
	AqaAsadiNames * obj = new AqaAsadiNames();
	clock_t start = clock();
	string my_answer = obj->getName(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "Mohammad Ali";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "Mohammad Reza";
	string p1 = "Yasaman Sadat";
	string p2 = "Baqer Ali";
	string p3 = "Girl";
	AqaAsadiNames * obj = new AqaAsadiNames();
	clock_t start = clock();
	string my_answer = obj->getName(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "Sadat Yasaman";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "Mohammad Reza";
	string p1 = "Yasaman Sadat";
	string p2 = "Umi Kulsum";
	string p3 = "Girl";
	AqaAsadiNames * obj = new AqaAsadiNames();
	clock_t start = clock();
	string my_answer = obj->getName(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "Yasaman Kulsum";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "Mohammad Reza";
	string p1 = "Yasaman Sadat";
	string p2 = "Umi Kulsum";
	string p3 = "Boy";
	AqaAsadiNames * obj = new AqaAsadiNames();
	clock_t start = clock();
	string my_answer = obj->getName(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "Reza Mohammad";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string p0 = "Mohammad Ali";
	string p1 = "Yasaman Sadat";
	string p2 = "Mohammad Reza";
	string p3 = "Boy";
	AqaAsadiNames * obj = new AqaAsadiNames();
	clock_t start = clock();
	string my_answer = obj->getName(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "Mohammad Reza";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string p0 = "Dhikrullah Ali";
	string p1 = "Umi Kulsum";
	string p2 = "Reza Hosseinzadeh";
	string p3 = "Boy";
	AqaAsadiNames * obj = new AqaAsadiNames();
	clock_t start = clock();
	string my_answer = obj->getName(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "Dhikrullah Hosseinzadeh";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
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
