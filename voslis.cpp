#include <algorithm>
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 5000;
const long long INF = 3e9;

int a[N];
int b[N];
long long F[N];

int main(){
    ios::sync_with_stdio(0);
    int n,m;
    while(cin >> n >> m){
        for(int i = 0;i<n;i++) cin >> a[i];
        for(int i = 0;i<m;i++) cin >> b[i];
        for(int i = 0;i<m;i++) F[i] = -INF;
        long long res = 0;
        for(int i = 0;i<n;i++){
            long long curMax = 0;
            for(int j = 0;j<m;j++){
                long long prevMax = curMax;
                curMax = max(F[j] + abs(a[i] - b[j]), curMax);
                if(a[i] == b[j]) F[j] = max(prevMax, F[j]);
                res = max(res, F[j]);
            }
        }
        cout << res << endl;
    }
    return 0;
}
