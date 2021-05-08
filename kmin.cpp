#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 5e4 + 1;


struct Node{
    int a, b, v;
} heap[N * 3];
int nHeap = 0;
int a[N];
int b[N];

void push(Node x){
    nHeap++;
    int cur = nHeap;
    while(cur > 1 && heap[cur / 2].v > x.v){
        heap[cur] = heap[cur/2];
        cur = cur/2;
    }
    heap[cur] = x;
}

Node pop(){
    Node res = heap[1];
    int cur = 1;
    Node x = heap[nHeap];
    nHeap--;
    while(cur * 2 <= nHeap){
        int child = cur * 2;
        if(cur * 2 + 1 <= nHeap && heap[cur * 2 + 1].v < heap[child].v)
            child += 1;
        if(heap[child].v < x.v){
            heap[cur] = heap[child];
            cur = child;
        }
        else 
            break;
    }
    heap[cur] = x;
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    int m,n,k;
    while(cin >> m >> n >> k){
        for(int i = 0;i<m;i++){
            cin >> a[i];
        }
        for(int i = 0;i<n;i++){
            cin >> b[i];
        }
        sort(a, a + m);
        sort(b, b + n);
        nHeap = 0;
        for(int i = 0;i<m;i++){
            push({i, 0, a[i] + b[0]});
        }
        for(int i = 0;i<k;i++){
            Node cur = pop();
            if(cur.b == n - 1) continue;
            push({cur.a, cur.b + 1, a[cur.a] + b[cur.b + 1]});
            cout << cur.v << endl;
        }
    }
    return 0;
}
