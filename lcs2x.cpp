#include <algorithm>
#include <iostream>
#include <memory.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 2e3;

int a[N];
int b[N];
int F[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> m >> n;
        for(int i = 1;i<=m;i++) cin >> a[i];
        for(int i = 1;i<=n;i++) cin >> b[i];
        memset(F, 0, sizeof F);
        int res = 0;
        for(int i = 1;i<=m;i++){
            int curMax = 0;
            for(int j = 1;j<=n;j++){
                int prevMax = curMax;
                if(b[j] * 2 <= a[i]) curMax = max(curMax, F[j]);
                if(a[i] == b[j]) F[j] = max(F[j], prevMax + 1);
                res = max(res, F[j]);
            }
        }
        cout << res << endl;
    }
    ios::sync_with_stdio(0);
    return 0;
}
