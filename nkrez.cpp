
#include <iostream>
#include <algorithm>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e4 + 1;

int a[N];
int b[N];
int F[N];

void quicksort(int * a,int * b,int L,int R){
    if(L >= R) return;
    int i = L;
    int j = R;
    int v = b[(L + R) / 2];
    while(i < j){
        while(b[i] < v) i++;
        while(b[j] > v) j--;
        if(i<=j){
            swap(a[i], a[j]);
            swap(b[i], b[j]);
            i++;
            j--;
        }
    }
    quicksort(a, b, L, j);
    quicksort(a, b, i ,R);
}

int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        for(int i = 0;i<n;i++){
            cin >> a[i] >> b[i];
        }
        quicksort(a, b, 0, n - 1);
        F[0] = b[0] - a[0];
        for(int i = 1;i<n;i++){
            F[i] = max(F[i-1], b[i] - a[i]);
            int jmax = upper_bound(b, b + i, a[i]) - b;
            jmax--;
            if(jmax >= 0 && jmax < i){
                F[i] = max(F[i], F[jmax] + b[i] - a[i]); 
            }
        }
        cout << F[n-1] << endl;
    }
    return 0;
}
