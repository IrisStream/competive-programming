
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e4;

int a[N];

bool isUk(int x){
    int k = (int)sqrt(x * 2);
    if(k * (k + 1) == x * 2) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        int prev = isUk(a[0]);
        int res = prev;
        for(int i = 1;i<n;i++){
            int cur = isUk(a[i]);
            if(a[i] >= a[i-1]){
                cur += prev;
            }
            res = max(res, cur);
            prev = cur;
        }
        cout << res << endl;
    }
    return 0;
}
