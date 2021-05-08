
#include <iostream>
#include <stack>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

char brack[10];
int state[20];
int n = 10;
int k = 3;

void print(){
    int cnt = 0;
    int cur = 0;
    stack<int> s;
    for(int i = 0;i<n;i++){
//        cout << state[i];
        if(state[i] % 2){
            s.push(state[i]);
            cur++;
        }
        else{
            if(s.empty()) return;
            if(state[i] - 1 != s.top())
                return;
            else
                s.pop();
            cnt = max(cnt, cur);
            cur--;
        }
    }
//    cout << endl;
    if(!s.empty()) return;
    if(cnt > k) return;
    for(int i = 0;i<n;i++){
        cout << brack[state[i]];
    }
    cout << endl;
}

void gen(int i){
    if(i == n){
        print();
        return;
    }
    for(int j = 1;j<=6;j++){
        state[i] = j;
        gen(i + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    brack[1] = '(';
    brack[2] = ')';
    brack[3] = '[';
    brack[4] = ']';
    brack[5] = '{';
    brack[6] = '}';
    cout << n << " " << k << endl;
    gen(0); 
    return 0;
}
