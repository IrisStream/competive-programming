
#include <iostream>
#include <string>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 2111;

int F[N][N];

int main(){
    ios::sync_with_stdio(0);
    string a, b;
    while(cin >> a >> b){
        int na = a.size();
        int nb = b.size();
        a = ' ' + a;
        b = ' ' + b;
        for(int i = 1;i<=na;i++){
            for(int j = 1;j<=nb;j++){
                if(a[i] == b[j]){
                    F[i][j] = F[i-1][j-1] + 1;
                }
                else{
                    F[i][j] = max(F[i-1][j], F[i][j-1]);
                }
            }
        }
        cout << F[na][nb] << endl;
    }
    return 0;
}
