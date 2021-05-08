#include <iostream>
using namespace std;

const int N = 1e5 + 1;

int a[N];

int main(){
    for(int i = 1;i<N;i++){
        for(int j = 2;i * j < N;j++){
            a[i * j] += i;
        }
    } 
    int L,R;
    int res;
    while(cin >> L >> R){
        res = 0;
        for(int i = L;i<=R;i++){
            if(a[i] > i){
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}
