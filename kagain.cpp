#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 3e4;

int a[N];
int L[N];
int R[N];

int main(){
    ios::sync_with_stdio(0);
    int test;
    cin >> test;
    int n;
    while(test--){
        cin >> n;
        for(int i = 0;i<n;i++){
            cin >> a[i];
        }
        stack<int> s;
        s.push(-1);
        for(int i = 0;i<n;i++){
            while(s.size() > 1 && a[s.top()] >= a[i]) s.pop();
            L[i] = s.top() + 1;
            s.push(i);
        }
        while(!s.empty()) s.pop();
        s.push(n);
        for(int i = n - 1;i>=0;i--){
            while(s.size() > 1 && a[s.top()] >= a[i]) s.pop();
            R[i] = s.top() - 1;
            s.push(i);
        }
        int res = 0;
        int l;
        int r;
        for(int i = 0;i<n;i++){
            if(res < (R[i] - L[i] + 1) * a[i]){
                res = (R[i] - L[i] + 1) * a[i];
                l = L[i];
                r = R[i];
            }
        }
        cout << res << " " << l + 1 << " " << r + 1 << endl;
    }
    return 0;
}
