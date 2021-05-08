#include <memory.h>
#include <iostream>
#include <math.h>
#include <sstream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e6+1;

bool prime[N];
int p[N];

long long concat(int x, int y){
    stringstream ss;
    long long ans;
    ss << x << y;
    ss >> ans;
    return ans;
}

bool isPrime(long long x){
    int i = 2;
    int tmp = sqrt(x);
    while(i <= tmp && x % i != 0) i++;
    return (i > tmp);
}

int main(){
    ios::sync_with_stdio(0);    
    memset(prime, 1, sizeof(prime));
    prime[1] = false;
    for(int i = 2;i<N;i++){
        if(!prime[i]) continue;
        for(int j = 2;i * j < N;j++){
            prime[i * j] = false;
        }
    }
    int n = 0;
    for(int i = 2;i<N;i++){
        if(prime[i])
            p[n++] = i;
    }
    int k;
    cin >> k;
    int cnt = 0;
    for(int i = 1;i<n;i++){
        long long x = concat(p[i-1],p[i]);
        if(isPrime(x)){
            cnt++;
            if(cnt == k){
                cout << x << endl;
                break;
            }
        }
        i++;
    }
    return 0;
}
