
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 5e4;
const int INF = 1e9;

int h[N];
int minH[N * 4], maxH[N * 4];

void build(int i,int L,int R){
    if(L == R){
        minH[i] = h[L];
        maxH[i] = h[L];
        return;
    }
    int mid = (L + R)/2;
    build(i * 2 + 1, L, mid);
    build(i * 2 + 2, mid + 1, R);
    minH[i] = min(minH[i * 2 + 1], minH[i * 2 + 2]);
    maxH[i] = max(maxH[i * 2 + 1], maxH[i * 2 + 2]);
}

int getMin(int k, int L,int R,int i,int j){
    if(i > R || j < L){
        return INF;
    }
    if(L >= i && R <=j){
        return minH[k];
    }
    int mid = (L + R) / 2;
    return min(getMin(k * 2 + 1, L, mid, i ,j), getMin(k * 2 + 2, mid + 1, R, i ,j));
}

int getMax(int k,int L,int R,int i,int j){
    if(i > R || j < L){
        return 0;
    }
    if(L >= i && R <=j){
        return maxH[k];
    }
    int mid = (L + R) / 2;
    return max(getMax(k * 2 + 1, L, mid, i, j), getMax(k * 2 + 2, mid + 1, R, i ,j));
}


int main(){
    ios::sync_with_stdio(0);
    int n, q;
    while(cin >> n >> q){
        for(int i = 0;i<n;i++){
            cin >> h[i];
        }
        build(0, 0, n - 1);
        int L,R;
        while(q--){
            cin >> L >> R;
            L--;
            R--;
            cout << getMax(0,0,n - 1, L, R) - getMin(0,0,n-1,L,R) << endl;
        }
    }
    return 0;
}
