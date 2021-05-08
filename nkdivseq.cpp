
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e5 + 10;

int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        int cur = 1;
        int div = 1;
        int nextDiv = 2;
        for(int i = 2;i<=n;i++){
            if(i == nextDiv){
                div++;
                cur = cur / div * div + div;
                nextDiv += div;
            }
            else cur += div;
        }
        cout << cur << endl;
    }
    return 0;
}
