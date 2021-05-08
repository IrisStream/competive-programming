#include <algorithm>
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e5;
const int INF = 1e9;

int a[N];
int F[N + 1];

int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        int sum = 0;
        F[N] = INF;
        for(int i = 0;i<n;i++) {
            cin >> a[i];
            sum += a[i];
            F[n] = min(F[n], sum);
        }
        int res = 0;
        for(int i = n - 1;i>=0;i--){
            F[i] = min(a[i], F[i+1] + a[i]);
            if(F[i] > 0) res++;
        }
        cout << res << endl;
    }
    return 0;
}
