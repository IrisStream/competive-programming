
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e3 + 1;

int a[N];
int F[N];

void quicksort(int * a,int L, int R){
    if(L >= R) return;
    int i = L;
    int j = R;
    int v = a[(L + R) / 2];
    while(i <= j){
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
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    quicksort(a, 0, n-1);
    F[0] = 1;
    F[1] = 1;
    int res = 1;
    int left;
    int right;
    for(int i = 2;i < n;i++){
        F[i] = 1;
        left = 0;
        right = i - 1;
        while(left < right){
            if(a[left] + a[right] > a[i])
                right--;
            else if(a[left] + a[right] < a[i]) 
                left++;
            else{
                F[i] = max(F[i], max(F[left] + 1, F[right] + 1));
                left++;
                right--;
            }
        }
        res = max(res, F[i]);
    }
    cout << res << endl;
    return 0;
}
