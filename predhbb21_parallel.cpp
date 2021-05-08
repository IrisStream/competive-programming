#include <algorithm>
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

bool isBox(int * a){
    sort(a, a + 12);
    for(int i = 0;i<3;i++){
        for(int j = 1;j<4;j++){
            if(a[i * 4 + j] != a[i * 4 + j - 1]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    int a[12];
    while(cin >> a[0]){
        if(a[0] == 0) break;
        for(int i = 1;i<12;i++) cin >> a[i];
        if(isBox(a))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
