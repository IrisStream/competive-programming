#include <memory.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll
#define time asdlfkjaldfj


const int N = 1e3;

vector< vector<int> > adj(N);
int time;
int topo[N];
bool visited[N];

void dfs1(int u){
    visited[u] = true;
    for(int i = 0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(visited[v]) continue;
        dfs1(v);
    }
    topo[time++] = u;
}

void dfs2(int u){
    visited[u] = true;
    for(int i = 0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(visited[v]) continue;
        dfs2(v);
    }
}

int main(){
    ios::sync_with_stdio(0);
    int n,m;
    while(cin >> n >> m){
        int u,v;
        for(int i = 0;i<m;i++){
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
        }
        memset(visited, 0, sizeof visited);
        for(int i = 0;i<n;i++){
            if(!visited[i]) dfs1(i);
        }

        memset(visited, 0, sizeof visited);
        int res = 0;
        for(int i = n-1;i>=0;i--){
            if(!visited[topo[i]]){
                dfs2(topo[i]);
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}
