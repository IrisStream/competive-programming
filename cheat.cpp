
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll
#define next asdfjdfl
#define prev cluojw

const int N = 1e5 + 1;

int next[N];
int prev[N];

int main(){
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        next[i] = i + 1;
        prev[i] = i - 1;
    }
    int last = 0;
    bool cheat = false;
    int cur;
    for(int i = 0;i<n;i++){
        cin >> cur;
        if(cur < last){
            cheat = true;
            break;
        }
        next[prev[cur]] = next[cur];
        prev[next[cur]] = prev[cur];
        last = prev[cur];
    }
    if(cheat == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
