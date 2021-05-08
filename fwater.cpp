#include <memory.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 5e2;
const int M = 1e5;

int par[N];

struct edge{
    int u, v, c;
};

vector<edge> edges;

bool cmp(edge& x, edge& y){
    return x.c < y.c;
}

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
    int n;
    while(cin >> n){
        int w;
        for(int i = 0;i<n;i++){
            cin >> w;
            edges.push_back({i + 1, n + 1, w});
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                cin >> w;
                if(i < j){
                    edges.push_back({i,j,w});
                }
            }
        }
        memset(par, 255, sizeof par);
        sort(edges.begin(), edges.end(), cmp);
        int res = 0;
        for(int i = 0;i<edges.size();i++){
            if(join(edges[i].u, edges[i].v)){
                res += edges[i].c;
            }
        }
        cout << res << endl;
    }
    return 0;
}
