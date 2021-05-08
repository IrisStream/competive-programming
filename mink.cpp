
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll
#define left adflk
#define right asdlfj

const int N = 17e3;

int a[N];
int left[N];
int right[N];

int main(){
    ios::sync_with_stdio(0);
    int test;
    cin >> test;
    int n,k;
    while(cin >> n >> k){
        for(int i = 0;i<n;i++){
            cin >> a[i];
        }
        for(int i = 0;i<n;i++){
            if(i % k == 0){
                left[i] = a[i];
            }
            else left[i] = min(left[i-1], a[i]);
        }
        for(int i = n-1;i>=0;i--){
            if(i % k == k - 1){
                right[i] = a[i];
            }
            else right[i] = min(right[i+1], a[i]);
        }
        for(int l = 0, r = k - 1;r<n;l++, r++){
            cout << min(right[l], left[r]) << " ";
        }
        cout << endl;
    }
    return 0;
}
