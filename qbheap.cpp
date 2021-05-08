
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int Q = 15e3;

int a[Q + 10];

int main(){
    ios::sync_with_stdio(0);
    char x;
    priority_queue<int> pq;
    while(cin >> x){
        if(x == '+'){
            int v;
            cin >> v;
            if(pq.size() < Q){
                pq.push(v);
            }
        }
        else if(x == '-'){
            int v = pq.top();
            while(!pq.empty() && pq.top() == v) pq.pop();
        }
        else break;
    }
    int res = 0;
    while(!pq.empty()){
        a[res++] = pq.top();
        while(!pq.empty() && pq.top() == a[res-1]) pq.pop();
    }
    cout << res << endl;
    for(int i = 0;i<res;i++) cout << a[i] << endl;
    return 0;
}
