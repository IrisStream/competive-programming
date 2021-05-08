#include <vector>
#include <memory.h>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

int a[30];
bool prime[51];
int num[8] = {2,2,4,96,1024,2880,81024,770144};
bool used[51];
int cnt;

void find(int pivot,int n){
    if(cnt >= 10000) return;
    if(pivot > n){
        if(prime[a[pivot-1]+1]){
            for(int i = 1;i<=n;i++) cout << a[i] << " ";
            cout << endl;
            cnt++;
        }
        return;
    }
    for(int i = 2;i <= n;i++){
        if(used[i]) continue;
        if(prime[i + a[pivot-1]] == false) continue;
        a[pivot] = i;
        used[i] = true;
        find(pivot+1,n);
        used[i] = false;
    }
}

int main(){
    memset(prime, 1, sizeof prime);
    prime[1] = false;
    for(int i = 2;i<=50;i++){
        if(prime[i] == false) continue;
        for(int j = 2;j*i<=50;j++){
            prime[i * j] = false;
        }
    }
    int k;
    cin >> k;
    cout << num[k - 2] << endl;
    cnt = 0;
    a[1] = 1;
    find(2, k * 2);
    return 0;
}
