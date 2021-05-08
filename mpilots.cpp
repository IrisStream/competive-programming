#include <queue>
#include <memory.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e4 + 1;

int a[N];
int b[N];
bool c[N];

int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        for(int i = 0;i<n;i++){
            cin >> a[i] >> b[i];
        }
        memset(c, 0, sizeof c);
        priority_queue< pair<int,int> > pq;
        int index;
        for(int i = 0;i<n;i++){
            pq.push({a[i] - b[i], i});
            if(i % 2 == 0){
                index = pq.top().second;
                pq.pop();
                c[index] = true;
            }
        }
        int res = 0;
        for(int i = 0;i<n;i++){
            if(c[i]) res += b[i];
            else res += a[i];
        }
        cout << res << endl;
    }
    return 0;
}
