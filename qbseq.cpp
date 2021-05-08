
#include <iostream>
#include <algorithm>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e3 + 1;
const int K = 50;
const int INF = 1e9;

int a[N];
int F[N][K];

int main(){
    ios::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
        a[i] = a[i] % k;
    }
    // F[i][j] là số phần tử nhiều nhất trong đoạn từ 0..i chia k dư j
    for(int i = 1;i<k;i++) F[0][i] = -INF;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<k;j++){
            F[i][j] = max(F[i - 1][j], F[i-1][(j - a[i] + k) % k] + 1);
        }
    }
    cout << F[n][0] << endl;
    return 0;
}
