#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 222;

int d[N][N];
int dx[4] = {1, 1, -1, -1};
int dy[4] = {-1, 1, -1, 1};

int bfs(pair<int,int> s, pair<int,int> g,int n){
    priority_queue< pair<int,int> > q;
    q.push(s);
    d[s.first][s.second] = 1;
    while(!q.empty()){
        auto [x, y] = q.top();
        if(x == g.first && y == g.second) return d[x][y];
        q.pop();
        for(int i = 0;i<4;i++){
            int x2 = x;
            int y2 = y;
            while(true){
                x2 = x2 + dx[i];
                y2 = y2 + dy[i];
                if(0 < x2 && x2 <= n && 0 < y2 && y2 <=n && d[x2][y2] == 0){
                    d[x2][y2] = d[x][y] + 1;
                    q.push({x2, y2});
                }
                else break;
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    int n,m,p,q,s,t;
    while(cin >> n >> m >> p >> q >> s >> t){
        int r,c;
        for(int i = 0;i<m;i++){
            cin >> r >> c;
            d[r][c] = -1;
        }
        cout << bfs({p,q}, {s, t}, n) << endl;
    }
    return 0;
}
