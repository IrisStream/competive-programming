
#include <iostream>
#include <memory.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e5 + 1;
const int MOD = 14062008;

int F[N];
bool a[N];

int main(){
    ios::sync_with_stdio(0);
    int n,k;
    while(cin >> n >> k){
        memset(a, 0, sizeof a);
        for(int i = 0;i<k;i++){
            int x;
            cin >> x;
            a[x] = true;
        }
        F[1] = 1;
        F[2] = 1 - a[2];
        for(int i = 2;i<=n;i++){
            if(a[i]){
                F[i] = 0;
            } else F[i] = (F[i-1] + F[i-2]) % MOD;
        }
        cout << F[n] << endl;
    }
    return 0;
}
