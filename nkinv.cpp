
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 6e4 + 1;

int c[N];

void update(int p){
    for(int i = p;i <= N;i += i & -i){
        c[i] += 1;
    }
}

int get(int p){
    int ans = 0;
    for(int i = p;i;i -= i & -i){
        ans += c[i];
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    int n;
    int cur;
    while(cin >> n){
        int res = 0;
        for(int i = 0;i<n;i++){
            cin >> cur;
            res += i - get(cur);
            update(cur);
        }
        cout << res << endl;
    }
    return 0;
}
