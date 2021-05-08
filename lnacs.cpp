
#include <iostream>
using namespace std;


#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e3 + 10;

int a[N];
int b[N];
int F[N][N];

int main(){
    ios::sync_with_stdio(0);
    int m,n;
    while(cin >> m >> n){
        for(int i = 1;i<=m;i++) cin >> a[i];
        for(int i = 1;i<=n;i++) cin >> b[i];
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                if(a[i] == b[j]){
                    if(i < 2 || j < 2)
                        F[i][j] = 1;
                    else
                        F[i][j] = F[i-2][j-2] + 1;
                }
                else F[i][j] = max(F[i-1][j], F[i][j-1]);
            }
        }
        cout << F[m][n] << endl;
    }
    return 0;
}
