#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll
#define time adflkj

const int N = 1e4 + 1;
const int M = 5e4 + 1;;

int time;
int low[N];
int num[N];
int joint[N];
int bridges;
int articulation_points;
vector< vector<int> > adj(N);

void dfs(int u,int pre){
    low[u] = num[u] = ++time;
    int child = 0;
    for(int v : adj[u]){
        if(v == pre) continue;
        if(!num[v]){
            dfs(v,u);
            low[u] = min(low[u], low[v]);
            if(low[v] == num[v]) bridges++;
            child++;
            if(u == pre){
                if(child > 1) joint[u] = true;
            }
            else if(low[v]>=num[u]) joint[u] = true;
        }
        else low[u] = min(low[u], num[v]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    int n,m;
    while(cin >> n >> m){
        int u,v;
        for(int i = 0;i<m;i++){
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 0;i<n;i++){
            if(!num[i]) dfs(i,i);
        }
        for(int i = 0;i<n;i++){
            if(joint[i]) articulation_points++;
        }
        cout << articulation_points << " " << bridges << endl;
    }
    return 0;
}
