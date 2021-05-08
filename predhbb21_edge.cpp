#include <algorithm>
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll
#define time adflkj

const int N = 1e6;
const int M = 2e6;

vector< vector<int> > adj(N);
int low[N];
int num[N];
bool joint[N];
int cnt[N];
int time;
vector<int> bridges;

int dfs(int u,int pre){
    num[u] = low[u] = ++time;
    int numNode = 1;
    for(int v : adj[u]){
        if(v == pre) continue;
        if(!num[v]){
            int numNodev = dfs(v,u);
            numNode += numNodev;
            low[u] = min(low[u], low[v]);
            if(low[v] == num[v]) {
                bridges.push_back(numNodev);
            }
        }
        else low[u] = min(low[u], num[v]);
    }
    return numNode;
}

int main(){
    ios::sync_with_stdio(0);
    int n,m;
    while(cin >> n >> m){
        int u,v;
        for(int i = 0;i<m;i++){
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        int components = 0;
        for(int i = 0;i<n;i++){
            if(!num[i]){
                cnt[components++] = dfs(i,i);
            }
        }
        long long res = 0;
        if(components > 2){
            res = 0;
        }
        else if(components == 2){
            res = 1LL * (m - bridges.size()) * cnt[0] * cnt[1];
        }
        else {
            res = (m - bridges.size()) * ((1LL * n * (n - 1)) / 2 - m);
            for(int bridge : bridges){
                res += 1LL * bridge * (n - bridge) - 1;
            }
        }
        cout << res << endl;
    }
    return 0;
}
