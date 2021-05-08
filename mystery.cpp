#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const long long MOD = 20122007;

long long pow(int n){
    if(n == 0) return 1;
    long long tmp = pow(n / 2);
    if(n % 2)
        return (((tmp * tmp) % MOD) * 3) % MOD;
    else
        return (tmp * tmp) % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    int a;
    while(cin >> a){
        int sqrta = sqrt(a);
        long long ans = 1;
        for(int i = 1; i<=sqrta;i++){
            if(a % i == 0){
                ans = (ans * (pow(i) + MOD - 1)) % MOD;
                if(i * i != a)
                    ans = (ans * (pow(a / i) + MOD - 1)) % MOD;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
