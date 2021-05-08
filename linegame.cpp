
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e6 + 1;

int main(){
    ios::sync_with_stdio(0);
    int n;
    long long cur;
    long long pos, newPos;
    long long neg, newNeg;
    long long res;
    while(cin >> n){
        pos = 0;
        neg = 0;
        res = 0;
        for(int i = 0;i<n;i++){
            cin >> cur;
            newPos = neg + cur;
            newNeg = pos - cur;
            pos = max(pos, newPos);
            neg = max(neg, newNeg);
            res = max(res, max(pos, neg));
        }
        cout << res << endl;
    }
    return 0;
}
