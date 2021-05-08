#include <algorithm>
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 4e5 + 1;

struct Node{
    int sum, a, b;
} heap[N];

int nHeap = 0;

void push(Node x){
    nHeap++;
    int cur = nHeap;
    while(cur > 1 && heap[cur / 2].sum > x.sum){
        heap[cur] = heap[cur / 2];
        cur = cur / 2;
    }
    heap[cur] = x;
}

void pop(){
    Node x = heap[nHeap];
    nHeap--;
    int cur = 1;
    while(cur * 2 <= nHeap){
        int child = cur * 2;
        if(cur * 2 + 1 <= nHeap && heap[cur * 2 + 1].sum < heap[child].sum)
            child += 1;
        if(x.sum > heap[child].sum){
            heap[cur] = heap[child];
            cur = child;
        }
        else break;
    }
    heap[cur] = x;
}

int main(){
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int a,b;
    for(int i = 0;i < n * 2;i++){
        cin >> a >> b;
        push({a - b, a, b});
    }
    int res = 0;
    for(int i = 0;i < n;i++){
        res += heap[1].a;
        pop();
    }
    for(int i = 0;i<n;i++){
        res += heap[1].b;
        pop();
    }
    cout << res << endl;
    return 0;
}
