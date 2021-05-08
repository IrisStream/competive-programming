#include <algorithm>
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e5;

int b[N];
int c[N];

int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        for(int i = 0;i<n;i++){
            cin >> b[i];
        }
        for(int i = 0;i<n;i++){
            cin >> c[i];
        }
        sort(b, b + n);
        sort(c, c + n);
        int res = abs(b[0] + c[0]);
        for(int i = 0;i<n;i++){
            int j = lower_bound(c, c + n, -b[i]) - c;
            if(j < n){
                res = min(res, abs(b[i] + c[j]));
            }
            if(j > 0){
                res = min(res, abs(b[i] + c[j-1]));
            }
        }
        cout << res << endl;
    }
    return 0;
}
