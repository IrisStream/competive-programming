
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

int fact(int n){
    if(n == 0) return 1;
    return n * fact(n - 1);
}

int main(){
    ios::sync_with_stdio(0);
    string s;
    int n;
    while(cin >> s){
        sort(s.begin(), s.end());
        n = s.size();
        int res = fact(n);
        int cnt = 1;
        for(int i = 1;i<n;i++){
            if(s[i] != s[i-1]){
                res = res / fact(cnt);
                cnt = 1;
            }
            else cnt++;
        }
        res = res / fact(cnt);
        cout << res << endl;
        for(int i = 0;i<res;i++){
            cout << s << endl;
            next_permutation(s.begin(), s.end());
        }
    }
    return 0;
}
