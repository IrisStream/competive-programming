#include <memory.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

struct edge{
    int u,v,c;
};

const int N = 1e4 + 1;
const int M = 15e3 + 1;

edge edges[M];

bool cmpEdge(edge x, edge y){
    return x.c < y.c;
}

int par[N];

int root(int x){
    if(par[x] < 0) return x;
    return par[x] = root(par[x]);
}

bool join(int x,int y){
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(par[x] < par[y]){
        par[x] += par[y];
        par[y] = x;
    }
    else{
        par[y] += par[x];
        par[x] = y;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    int m,n;
    while(cin >> n >> m){
        for(int i = 0;i<m;i++){
            cin >> edges[i].u >> edges[i].v >> edges[i].c;
        }
        memset(par, 255, sizeof par);
        sort(edges, edges + m, cmpEdge);
        int res = 0;
        for(int i = 0;i<m;i++){
            if(join(edges[i].u, edges[i].v)){
                res += edges[i].c;
            } 
        }
        cout << res << endl;
    }
    return 0;
}
