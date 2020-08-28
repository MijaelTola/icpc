#include <bits/stdc++.h>

using namespace std;

class EnlargeTheCave {
    public:
        vector <string> enlarge(vector <string>, int);
};

int n,m,da;
int vis[55][55];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool check (int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < m;
}

 vector<string> bfs(int x, int y, vector<string> cave) {
        queue<pair<int,int> > q;
        q.push({x,y});
        while(!q.empty() and da) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            if(vis[x][y]) continue;
            da--;
            vis[x][y] = 1;
            cave[x][y] = '.';
            for (int i = 0; i < 4; ++i) {
                int u = x + dx[i];
                int v = y + dy[i];
                if(check(u,v)) {
                    if(cave[u][v] == '#') {
                        bool flag = 1;
                        for (int j = 0; j < 4; ++j) {
                            int uu = u + dx[j];
                            int vv = v + dy[j];
                            if(check(uu,vv)) 
                                flag &= cave[uu][vv] != 'K';
                        }
                        if(flag) q.push({u,v});

                    } else if(cave[u][v] == '.') q.push({u,v});
                }
            }
        }
        return cave;
    };

vector <string> EnlargeTheCave::enlarge(vector <string> cave, int desiredArea) {


    n = cave.size();
    m = cave[0].size();
    da = desiredArea;
    

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(!vis[i][j] and cave[i][j] == '.') 
                cave = bfs(i,j, cave);
        }
    }
    if(da) return {};
    return cave;
}


double test0() {
    string t0[] = {".##",
        "###",
        "###"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 7;
    EnlargeTheCave * obj = new EnlargeTheCave();
    clock_t start = clock();
    vector <string> my_answer = obj->enlarge(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string t2[] = {"...", "..#", "..#" };
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0) {
        cout <<"\""<<p2[0]<<"\"";
        for (int i=1; i<(int)p2.size(); i++)
            cout <<", \"" <<p2[i]<<"\"";
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0) {
        cout <<"\""<<my_answer[0]<<"\"";
        for (int i=1; i<(int)my_answer.size(); i++)
            cout <<", \"" <<my_answer[i]<<"\"";
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p2) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1() {
    string t0[] = {".##",
        "##K",
        "###"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 5;
    EnlargeTheCave * obj = new EnlargeTheCave();
    clock_t start = clock();
    vector <string> my_answer = obj->enlarge(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string t2[] = {"..#", ".#K", "..#" };
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0) {
        cout <<"\""<<p2[0]<<"\"";
        for (int i=1; i<(int)p2.size(); i++)
            cout <<", \"" <<p2[i]<<"\"";
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0) {
        cout <<"\""<<my_answer[0]<<"\"";
        for (int i=1; i<(int)my_answer.size(); i++)
            cout <<", \"" <<my_answer[i]<<"\"";
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p2) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2() {
    string t0[] = {".##",
        "##K",
        "###"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 6;
    EnlargeTheCave * obj = new EnlargeTheCave();
    clock_t start = clock();
    vector <string> my_answer = obj->enlarge(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    vector <string> p2;
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0) {
        cout <<"\""<<p2[0]<<"\"";
        for (int i=1; i<(int)p2.size(); i++)
            cout <<", \"" <<p2[i]<<"\"";
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0) {
        cout <<"\""<<my_answer[0]<<"\"";
        for (int i=1; i<(int)my_answer.size(); i++)
            cout <<", \"" <<my_answer[i]<<"\"";
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p2) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3() {
    string t0[] = {"###K########",
        "#.#K########",
        "..#K########",
        "############"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 10;
    EnlargeTheCave * obj = new EnlargeTheCave();
    clock_t start = clock();
    vector <string> my_answer = obj->enlarge(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    vector <string> p2;
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0) {
        cout <<"\""<<p2[0]<<"\"";
        for (int i=1; i<(int)p2.size(); i++)
            cout <<", \"" <<p2[i]<<"\"";
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0) {
        cout <<"\""<<my_answer[0]<<"\"";
        for (int i=1; i<(int)my_answer.size(); i++)
            cout <<", \"" <<my_answer[i]<<"\"";
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p2) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test4() {
    string t0[] = {"###############",
        "###############",
        "##K###..####K##",
        "######..#######",
        "###############",
        "##K#########K##",
        "###############",
        "###############"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 82;
    EnlargeTheCave * obj = new EnlargeTheCave();
    clock_t start = clock();
    vector <string> my_answer = obj->enlarge(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string t2[] = {"...............", "..#.........#..", ".#K#.......#K##", "###.........###", "###.........###", "##K#.......#K##", "###.........###", "#............##" };
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0) {
        cout <<"\""<<p2[0]<<"\"";
        for (int i=1; i<(int)p2.size(); i++)
            cout <<", \"" <<p2[i]<<"\"";
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0) {
        cout <<"\""<<my_answer[0]<<"\"";
        for (int i=1; i<(int)my_answer.size(); i++)
            cout <<", \"" <<my_answer[i]<<"\"";
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p2) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test5() {
    string t0[] = {"#K#K###..###K#K##"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 6;
    EnlargeTheCave * obj = new EnlargeTheCave();
    clock_t start = clock();
    vector <string> my_answer = obj->enlarge(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string t2[] = {"#K#K#......#K#K##" };
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0) {
        cout <<"\""<<p2[0]<<"\"";
        for (int i=1; i<(int)p2.size(); i++)
            cout <<", \"" <<p2[i]<<"\"";
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0) {
        cout <<"\""<<my_answer[0]<<"\"";
        for (int i=1; i<(int)my_answer.size(); i++)
            cout <<", \"" <<my_answer[i]<<"\"";
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p2) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test6() {
    string t0[] = {"....",
        "....",
        "...."};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 12;
    EnlargeTheCave * obj = new EnlargeTheCave();
    clock_t start = clock();
    vector <string> my_answer = obj->enlarge(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string t2[] = {"....", "....", "...." };
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0) {
        cout <<"\""<<p2[0]<<"\"";
        for (int i=1; i<(int)p2.size(); i++)
            cout <<", \"" <<p2[i]<<"\"";
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0) {
        cout <<"\""<<my_answer[0]<<"\"";
        for (int i=1; i<(int)my_answer.size(); i++)
            cout <<", \"" <<my_answer[i]<<"\"";
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p2) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}

double test7() {
string t0[] = {"################################################", "################################################", "################################################", "################################################", "################################################", "################################################", "################################################", "################################################", "################################################", "################################################", "################################################", "##############################K#################", "################################################", "################################################", "################################################", "################################################", "################################################", "################################################", "################################################", "################################################", "################################################", "################################################", "################################################", "################################################", "################################################", "#############.#...##############################", "###########.......##############################", "###########.........############################", "###########.........#..#########################", "#########...............########################", "###########................###########K#########", "###########.................####################", "#######.....................###.################", "#######.........................########K#######", "#########.......................################", "###########...................##################", "###########...................##################", "#########....................######K############", "#########....................###################", "#########....................###################", "############...................#################", "###########...................##################", "###########....................#################", "############.................#.#################", "############.................###################", "############.................###################", "#############.##............####################", "################....#.....######################"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 580;
    EnlargeTheCave * obj = new EnlargeTheCave();
    clock_t start = clock();
    vector <string> my_answer = obj->enlarge(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string t2[] = {"....", "....", "...." };
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0) {
        cout <<"\""<<p2[0]<<"\"";
        for (int i=1; i<(int)p2.size(); i++)
            cout <<", \"" <<p2[i]<<"\"";
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0) {
        cout <<"\""<<my_answer[0]<<"\"";
        for (int i=1; i<(int)my_answer.size(); i++)
            cout <<", \"" <<my_answer[i]<<"\"";
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p2) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}


int main() {
    test7();
    return 0;
}
/*
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

   time = test6();
   if (time < 0)
   errors = true;

   if (!errors)
   cout <<"You're a stud (at least on the example cases)!" <<endl;
   else
   cout <<"Some of the test cases had errors." <<endl;
   }
   */
//Powered by [KawigiEdit] 2.0!
