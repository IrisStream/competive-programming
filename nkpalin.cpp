
#include <iostream>
#include <string>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 2e3+3;

int F[N][N];
string s;

void print(int L,int R){
    if(L == R){
        cout << s[L];
        return;
    }
    if(s[L] == s[R]){
        cout << s[L];
        print(L+1, R-1);
        cout << s[L];
    }
    else{
        if(F[L][R] == F[L + 1][R]){
            print(L+1, R);
        }
        else{
            print(L, R-1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    while(cin >> s){
        int n = s.length();
        s = ' ' + s;
        for(int i = n;i>0;i--){
            F[i][i] = 1;
            for(int j = i+1;j<=n;j++){
                if(s[i] == s[j]){
                    F[i][j] = F[i+1][j-1] + 2;
                }
                else{
                    F[i][j] = max(F[i+1][j], F[i][j-1]);
                }
            }
        }
        print(1, n);
    }
    return 0;
}
