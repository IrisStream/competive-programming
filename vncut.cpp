
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

int main(){
    ios::sync_with_stdio(0);
    int m,n;
    while(cin >> m >> n){
        int res = 0;
        int r;
        while(n != 0){
            r = m % n;
            res += m / n;
            m = n;
            n = r;
        }
        cout << res << endl;
    }
    return 0;
}
