#include <memory.h>
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1000;
const int M = 10000;

struct edge{
    int u;
    int v;
    int c;
};

edge edges[M];

void quicksort(edge * a, int L, int R){
    if(L>=R) return;
    int i = L;
    int j = R;
    int v = a[(L + R)/2].c;
    while(i<j){
        while(a[i].c < v) i++;
        while(a[j].c > v) j--;
        if(i<=j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    quicksort(a, L, j);
    quicksort(a, i, R);
}

int par[N];

int find(int x){
    if(par[x] < 0) return x;
    return par[x] = find(par[x]);
}

bool join(int x, int y){
    x = find(x);
    y = find(y);
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
    int n, m;
    while(cin >> n >> m){
        for(int i = 0;i<m;i++){
            cin >> edges[i].u >> edges[i].v >> edges[i].c;
        }
        memset(par, 255, sizeof par);
        quicksort(edges, 0, m - 1);
        int res = 0;
        for(int i = 0;i < m;i++){
            if(join(edges[i].u, edges[i].v)){
                res = max(res, edges[i].c);
            }
        }
        cout << res << endl;
    }
    return 0;
}
