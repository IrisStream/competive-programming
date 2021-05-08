
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

int main(){
    ios::sync_with_stdio(0);
    int test;
    cin >> test;
    string line;
    getline(cin, line); 
    while(test--){
        cin.clear();
        getline(cin, line); 
        stringstream ss(line);
        string t;
        int curlen = 0;
        int cur = 0;
        int max = 0;
        while(ss >> t){
//            cout << t << " ";
            if(curlen != t.size()){
                if(max < cur) max = cur;
                cur = 1;
                curlen = t.size();
            }
            else{
                cur += 1;
            }
        }
        if(max < cur) max = cur;
        cout << max << endl;
    }
    return 0;
}
