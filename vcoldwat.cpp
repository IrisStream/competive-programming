#include <memory.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e5;

vector< vector<int> > adj(N);

int d[N];

void dfs(int u){
    for(int i = 0;i<adj[u].size();i++){
        int v = adj[u][i];
        d[v] = d[u] + 1;
        dfs(v);
    }
}

int main(){
    ios::sync_with_stdio(0);
    int n,c;
    while(cin >> n >> c){
        int u,v1,v2;
        while(c--){
            cin >> u >> v1 >> v2;
            adj[u].push_back(v1);
            adj[u].push_back(v2);
        }
        memset(d, 0, sizeof d);
        d[1] = 1;
        dfs(1);
        for(int i = 1;i<=n;i++) cout << d[i] << endl;
    }
    return 0;
}
