
#include <iostream>
#include <memory.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e4;

int par[N];

int root(int x){
    if(par[x] < 0) return x;
    return par[x] = root(par[x]);
}

void join(int x,int y){
    x = root(x);
    y = root(y);
    if(x == y) return;
    if(par[x] < par[y]){
        par[x] += par[y];
        par[y] = x;
    }
    else{
        par[y] += par[x];
        par[x] = y;
    }
}

int main(){
    ios::sync_with_stdio(0);
    int p;
    while(cin >> p){
        memset(par, 255, sizeof par);
        int x,y,c;
        while(p--){
            cin >> x >> y >> c;
            if(c == 1){
                join(x,y);
            }
            else cout << (root(x) == root(y)) << endl;
        }
    }
    return 0;
}
