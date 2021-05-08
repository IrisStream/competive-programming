#include <algorithm>
#include <memory.h>
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e3 + 1;
const int K = 5e2 + 1;
const int MOD = 9901;
const int INF = 1e9;

int F[N][K];
int p[N];

int calc(int n,int k){
    if(n % 2 == 0) return 0;
    if(n > p[k] - 1) return 0;
    if(n == 1){
        return 1;
    }
    if(F[n][k] != -1) return F[n][k];
    F[n][k] = 0;
    for(int i = 1;i<n;i+=2){
        F[n][k] = (F[n][k] + calc(n - i - 1, k - 1) * calc(i, k - 1)) % MOD;
    }
    return F[n][k];
}

int main(){
    ios::sync_with_stdio(0);
    int n,k;
    while(cin >> n >> k){
        memset(F, 255, sizeof F);
        p[0] = 1;
        for(int i = 1;i<=n;i++) p[i] = INF;
        for(int i = 1;p[i-1] <= n;i++){
            p[i] = p[i - 1] * 2;
        }
        cout << (calc(n, k) - calc(n, k - 1) + MOD) % MOD << endl;
    }
    return 0;
}
