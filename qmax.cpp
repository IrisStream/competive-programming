
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 5e4 + 1;

int a[N];
int it[N * 4];

void build(int i,int L,int R){
    if(L == R){
        it[i] = a[L];
        return;
    }
    int mid = (L + R) / 2;
    build(i * 2 + 1,L , mid);
    build(i * 2 + 2,mid + 1, R);
    it[i] = max(it[i * 2 + 1], it[i * 2 + 2]);
}

int getMax(int k,int L, int R,int i,int j){
    if(i > R || j < L){
        return 0;
    }
    if(L >= i && R <= j){
        return it[k];
    }
    int mid = (L + R) / 2;
    return max(getMax(k * 2 + 1,L, mid, i ,j), getMax(k * 2 + 2,mid + 1, R, i ,j));
}

int main(){
    ios::sync_with_stdio(0);
    int n,m,q;
    while(cin >> n >> m){
        int u,v, value;
        for(int i = 0;i<m;i++){
            cin >> u >> v >> value;
            a[u - 1] += value;
            a[v] -= value;
        }
        for(int i = 1;i<n;i++){
            a[i] += a[i-1];
        }
        build(0,0,n-1);
        cin >> q;
        while(q--){
            cin >> u >> v;
            cout << getMax(0,0,n-1,u - 1,v - 1) << endl;
        }
        
    }
    return 0;
}
