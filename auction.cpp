
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1000;

int p[N];

void quicksort(int * a,int L,int R){
    if(L>=R) return;
    int i = L;
    int j = R;
    int v = a[(L + R)/2];
    while(i<j){
        while(a[i] < v) i++;
        while(a[j] > v) j--;
        if(i<=j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    quicksort(a, L, j);
    quicksort(a, i, R);
}

int main(){
    ios::sync_with_stdio(0);
    int n,m;
    while(cin >> n >> m){
        for(int i = 0;i<m;i++){
            cin >> p[i];
        }
        quicksort(p, 0, m - 1);
        int res = 0;
        int cost = -1;
        for(int i = 0;i<m;i++){
            if(res < p[i] * min(n, m - i)){
                res = p[i] * min(n, m - i);
                cost = p[i];
            }
        }
        cout << cost << " " << res << endl;
    }
    return 0;
}
