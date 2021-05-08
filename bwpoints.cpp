
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e5;

int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        vector< pair<int,int> >a(n * 2);
        for(int i = 0;i<n;i++){
            cin >> a[i].first;
            a[i].second = 1;
        }
        for(int i = n;i<n * 2;i++){
            cin >> a[i].first;
            a[i].second = 0;
        }
        sort(a.begin(),a.end());
        int res = 0;
        for(int i =1;i<a.size();i++){
            if(a[i].second != a[i-1].second){
                res++;
                i++;
            }
        }
        cout << res << endl;
    }
    return 0;
}
