
#include <iostream>
#include <algorithm>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e5 + 1;

int a[N];

int main(){
    ios::sync_with_stdio(0);
    a[0] = 0;
    a[1] = 1;
    for(int i = 2;i<=N;i++){
        if(i % 2==0){
            a[i] = a[i/2];
        }
        else{
            a[i] = a[i/2] + a[i/2+1];
        }
    }
    for(int i = 2;i<=N;i++){
        a[i] = max(a[i], a[i-1]);
    }
    int t;
    cin >> t;
    int n;
    while(t--){
        cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}
