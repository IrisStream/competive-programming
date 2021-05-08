
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

int groupCount(int n,int k){
    if(n <= k || (n - k) & 1){
        return 1;
    }
    return groupCount((n - k) / 2, k) + groupCount((n - k) / 2 + k, k);
}

int main(){
    ios::sync_with_stdio(0);
    int n,k;
    while(cin >> n >> k){
        cout << groupCount(n,k);
    }
    return 0;
}
