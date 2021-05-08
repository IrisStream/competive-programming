
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 25e3 + 10;

long long a[N];
long long F[N];

int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        for(int i = 1;i<n;i++){
            cin >> a[i];
        }
        F[0] = 0;
        F[1] = a[1];
        F[2] = a[1] + a[2];
        for(int i = 3;i<n;i++){
            F[i] = min(F[i-1] + a[i],F[i-2] + a[i]);
        }
        cout << F[n - 1] << endl;
    }
    return 0;
}
