
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e3;

vector< vector< pair<int,int> > > adj(N);
int rot[N];
int n;

void find(int u){
    for(int i = 0;i < adj[u].size();i++){
        auto [v,c] = adj[u][i];
        rot[v] = rot[u] ^ c;
        find(v); 
    }
}

int main(){
    ios::sync_with_stdio(0);
    while(cin >> n){
        int u,v,c;
        for(int i = 0;i<n-1;i++){
            cin >> u >> v >> c;
            adj[u - 1].push_back({v - 1,c});
        }
        find(0);
        cout << rot[n-1] << endl;
    }
    return 0;
}
