#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e6 + 1;
const long long MOD = 1e9 + 7;
const int BASE = 31;

long long p[N];
long long ha[N];
long long hb;

long long getHash(int i,int j){
    return (ha[j] - ha[i - 1] * p[j - i + 1] + MOD * MOD) % MOD;
}

int main(){
    p[0] = 1;
    for(int i = 1;i<N;i++){
        p[i] = (p[i-1] * BASE) % MOD;
    }
    ios::sync_with_stdio(0);
    string a, b;
    while(cin >> a >> b){
        int n = a.size();
        int m = b.size();
        a = ' ' + a;
        ha[0] = 0;
        for(int i = 1;i<=n;i++){
            ha[i] = (ha[i-1] * BASE + a[i] - 'a') % MOD;
        }
        hb = 0;
        for(int i = 0;i<m;i++){
            hb = (hb * BASE + b[i] - 'a') % MOD;
        }
        for(int i = 1;i<=n - m + 1;i++){
            if(hb == getHash(i,i + m - 1)){
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
