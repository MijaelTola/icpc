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

class EllysPronunciation {
public:
	int getGood(vector <string>);
};

int EllysPronunciation::getGood(vector <string> words) {
	
    int ans = 0;
    for (auto x: words) {
        int a = 0, b = 0;
        for (auto y: x) {
            if(y == 'a' or y == 'e' or y == 'i' or y == 'o' or y == 'u') a++;
            else b++;
        }
        ans += b == a;
    }
    return ans;
}


double test0() {
	string t0[] = {"wrath", "allure", "vorliebe", "abneigung", "amor", "voulez", "ecoeurement", "odiar"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	EllysPronunciation * obj = new EllysPronunciation();
	clock_t start = clock();
	int my_answer = obj->getGood(p0);
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
double test1() {
	string t0[] = {"schornsteinfeger", "schmetterling", "lohnsteuerabzugsbescheinigung", "shifffahrt",
 "deutsch", "ist", "die", "schoenste", "sprache", "auf", "der", "welt"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	EllysPronunciation * obj = new EllysPronunciation();
	clock_t start = clock();
	int my_answer = obj->getGood(p0);
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
	string t0[] = {"hearing", "vision", "smell", "touch", "taste",
 "denial", "anger", "bargaining", "depression", "acceptance",
 "war", "famine", "plague", "death",
 "pog", "story", "sarah", "gender", "baleen",
 "posh", "sporty", "scary", "ginger", "baby", "spice"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	EllysPronunciation * obj = new EllysPronunciation();
	clock_t start = clock();
	int my_answer = obj->getGood(p0);
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
double test3() {
	string t0[] = {"this", "was", "a", "triumph",
 "i", "am", "making", "a", "note", "here", "huge", "success",
 "its", "hard", "to", "overstate", "my", "satisfaction"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	EllysPronunciation * obj = new EllysPronunciation();
	clock_t start = clock();
	int my_answer = obj->getGood(p0);
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
double test4() {
	string t0[] = {"wir", "werden", "alle", "sterben", "haltet", "euch", "bereit",
 "die", "zeichen", "sind", "eindeutig", "bald", "ist", "es", "soweit",
 "vielleicht", "schon", "heute", "abend", "vielleicht", "in", "einem", "jahr",
 "doch", "alle", "verden", "sterben", "traurig", "aber", "wahr"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	EllysPronunciation * obj = new EllysPronunciation();
	clock_t start = clock();
	int my_answer = obj->getGood(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 8;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
