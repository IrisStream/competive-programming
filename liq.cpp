#include <set>
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 3e4;

int a[N];

int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        for(int i = 0;i<n;i++){
            cin >> a[i];
        }
        multiset<int> s;
        for(auto x : a){
            auto it =  s.lower_bound(x);
            if(it != s.end()){
                s.erase(it);
            }
            s.insert(x);
        }
        cout << s.size() << "\n";
    }
    return 0;
}
