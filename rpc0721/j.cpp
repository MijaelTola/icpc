#include <bits/stdc++.h>

using namespace std;

int m[9][9];

bool empty( int r, int c, int val){
    if(m[r][c] != 0)
        return false;

    for(int j = 0; j < 9; j++)
        if(m[r][j] == val)
            return false;


    for(int i = 0; i < 9; i++)
        if(m[i][c] == val)
            return false;


    for(int i = (r / 3) * 3; i < (r / 3) * 3 + 3; i++)
        for(int j = (c / 3) * 3; j < (c / 3) * 3 + 3; j++)
            if(m[i][j] == val)
                return false;

    return true;
}


void can( int r, int c, vector<int>& pbs){
    pbs.resize(0);
    for(int val = 1; val <= 9; val++){
        if(empty(r, c, val))
            pbs.push_back(val);
    }
}

bool is(){
    bool flag = false;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            vector<int> pbs;
            can(i, j, pbs);
            if(pbs.size()== 1){
                flag = true;
                m[i][j] = pbs[0];
            }
        }
    }
    return flag;
}

bool uno(){
    bool flag = false;
    for(int r = 0; r < 9; r++){
        for(int val = 1; val <= 9; val++){
            vector<int> pl;
            for(int c = 0; c < 9; c++)
                if(empty(r,c,val))
                    pl.push_back(c);
            if(pl.size() == 1){
                flag = true;
                m[r][pl[0]] = val;
            }
        }
    }
    return flag;
}

bool dos(){
    bool flag = false;
    for(int c = 0; c < 9; c++){
        for(int val = 1; val <= 9; val++){
            vector<int> pl;
            for(int r = 0; r < 9; r++)
                if(empty(r, c, val)){
                    pl.push_back(r);
                }
            if(pl.size() == 1){
                flag = true;
                m[pl[0]][c] = val;
            }
        }
    }
    return flag;
}

bool check2(int r, int c){
    bool flag = false;
    for(int val = 1; val <= 9; val++){
        int num_flag = 0;
        int flag1 = -1;
        int flag2 = -1;
        for(int i = r; i < r+3; i++)
            for(int j = c; j < c+3; j++)
                if(empty(i, j, val)){
                    num_flag++;
                    flag1 = i;
                    flag2 = j;
                }
        if(num_flag == 1){
            flag = true;
            m[flag1][flag2] = val;
        }
    }
    return flag;
}

bool primero(){
    bool flag = false;
    for(int r = 0;r < 9; r = r+3)
        for(int c = 0; c < 9; c = c+3)
            if(check2(r,c))
                flag = true;
    return flag;
}

bool segundo(){
    return uno() || dos() || primero();
}

bool check(){
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            if(m[i][j] == 0)
                return false;
    return true;
}

int main(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++)
            cin >> m[i][j];
    }

    bool flag2 = true;
    bool flag = false;
    while(!flag && flag2){
        flag2 = false;
        bool cur = primero();
        if(cur)
            flag2 = true;
        cur = uno() || dos() || primero();
        if(cur)
            flag2 = true;
        flag = check();
    }

    if(flag) cout << "Easy" << "\n";
    else cout << "Not easy" << "\n";
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(m[i][j] != 0)
                cout << m[i][j] << " ";
            else
                cout << "." << " ";
        }
        cout << "\n";
    }
    return 0;
}
