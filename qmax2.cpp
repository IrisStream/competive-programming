
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 5e4;

struct Node{
    int value;
    int lazy;
} nodes[N * 4];

void down(int id){
    int t = nodes[id].lazy;
    nodes[id * 2 + 1].value += t;
    nodes[id * 2 + 1].lazy += t;

    nodes[id * 2 + 2].value += t;
    nodes[id * 2 + 2].lazy += t;
    nodes[id].lazy = 0;
}

void update(int k,int L,int R,int i,int j,int v){
    if(i > R || j < L) return;
    if(i <= L && j >= R){
        nodes[k].value += v;
        nodes[k].lazy += v;
        return;
    }
    down(k);
    int mid = (L + R) / 2;
    update(k * 2 + 1, L, mid,i, j, v);
    update(k * 2 + 2, mid + 1, R, i, j, v);
    nodes[k].value = max(nodes[k * 2 + 1].value, nodes[k * 2 + 2].value);
}

int get(int k,int L,int R,int i,int j){
    if(i > R || j < L) return 0;
    if(i <= L && j >= R) return nodes[k].value;
    down(k);
    int mid = (L + R) / 2;
    return max(get(k * 2 + 1, L, mid, i, j), get(k * 2 + 2, mid + 1, R, i, j));
}

int main(){
    ios::sync_with_stdio(0);
    int n,m;
    while(cin >> n >> m){
        while(m--){
            int c,x,y,value;
            cin >> c >> x >> y;
            if(c == 0){
                cin >> value;
                update(0,0,n-1,x-1,y-1,value);
            }
            else cout << get(0,0,n-1,x-1,y-1) << endl;
        }
    }
    return 0;
}
