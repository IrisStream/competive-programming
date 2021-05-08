#include <string>
#include <memory.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 111;

char a[N][N];
int d[N][N];

int bfs(int u, int v){
    queue< pair<int,int> > q;
    q.push({u,v});
    memset(d, -1, sizeof d);
    d[u][v] = 0;
    while(!q.empty()){
        auto [x,y] = q.front();
        if(a[x][y] == 'B')
            return d[x][y];
        q.pop();
        for(int dx = -1;dx <= 1;dx++){
            for(int dy = -1;dy <= 1;dy++){
                if(dx*dx + dy * dy == 1){
                    if(a[x + dx][y + dy] == '*') continue;
                    if(d[x + dx][y + dy] >= 0) continue;
                    d[x + dx][y + dy] = d[x][y] + 1;
                    q.push({x + dx, y + dy});
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    int nRow, nCol;
    while(cin>> nRow >> nCol){
        memset(a, '*', sizeof(a));
        
        for(int i = 1;i<=nRow;i++){
            for(int j = 1;j<=nCol;j++){
                cin >> a[i][j];
            }
        }

        for(int i = 1;i<=nRow;i++){
            for(int j = 1;j<=nCol;j++){
                if(a[i][j] == 'C'){
                    cout << bfs(i,j) << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
