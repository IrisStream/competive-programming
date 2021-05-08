
#include <iostream>
#include <algorithm>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e5;

int a[N];

int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        int res = 0;
        for(int i = 0;i<n;i++){
            cin >> a[i];
            res += a[i];
        }
        sort(a, a + n);
        for(int i = 0;i<n - i - 1;i++){
            res += (a[n - i - 1] - a[i]);
        }
        cout << res << endl;
    }
    return 0;
}
