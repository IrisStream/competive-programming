
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e5;

int main(){
    ios::sync_with_stdio(0);
    stringstream ss;
    for(int i = 1;i<=N;i++)
        ss << i;
    string s = ss.str();
    int n;
    while(cin >> n){
        cout << s.find(to_string(n)) + 1 << endl;
    }
    return 0;
}
