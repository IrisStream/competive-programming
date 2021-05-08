
#include <iostream>
#include <string>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const long long MOD = 1e9 + 7;
const long long BASE = 31;
const int N = 300;

long long p[N];
long long ha[N];
long long hb[N];

int main(){
    ios::sync_with_stdio(0);
    p[0] = 1;
    for(int i = 1;i<N;i++){
        p[i] = (p[i - 1] * BASE) % MOD;
    }
    string a, b;
    int n,m;
    while(cin >> a >> b){
        m = a.size();
        n = b.size();
        b = ' ' + b;
        ha[m] = 0;
        hb[0] = 0;
        int res = m + n;
        for(int i = 1;i<=m;i++){
            ha[m - i] = (p[i - 1] * (a[m - i] - 'a') + ha[m - i + 1]) % MOD;
            hb[i] = (hb[i-1] * BASE + b[i] - 'a') % MOD;
            if(hb[i] == ha[m - i]){
                res = m + n - i;
            }
        }
        cout << res << endl;
    }
    return 0;
}
