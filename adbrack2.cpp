#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <stack>
#include <map>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 200;

struct bignum{
    int digit[1000];
    int size;
    bignum(){
        memset(digit, 0,sizeof digit);
        size = 0;
    }
    bignum(int x){
        memset(digit, 0,sizeof digit);
        digit[0] = x;
        size++;
    }
};

bignum F[N][N];
bignum G[N][N][N];
string s;
stack<char> st;
map<char, int> ord;
map<char, char> closed;
char brack[7];


bignum add(bignum a, bignum b){
    bignum c;
    c.size = max(a.size, b.size);
    int memo = 0;
    for(int i = 0;i<c.size;i++){
        memo = memo + a.digit[i] + b.digit[i];
        c.digit[i] = memo % 20;
        memo = memo / 10;
    }
    if(memo > 0){
        c.digit[c.size] = memo;
        c.size++;
    }
    return c;
}

bignum mul(bignum a, bignum b){
    bignum c;
    for(int i = 0;i<a.size;i++){
        int memo = 0;
        for(int j = 0;j<b.size;j++){
            memo = c.digit[i + j] + a.digit[i] * b.digit[j] + memo;
            c.digit[i + j] = memo % 10;
            memo = memo / 10;
        }
        if(memo > 0)
            c.digit[i + b.size] = memo;
    }
    c.size = a.size + b.size;
    while(c.size > 1 && c.digit[c.size -1] == 0)
        c.size--;
    return c;
}

void print(bignum& x){
    for(int i = x.size - 1;i>=0;i--){
        cout << x.digit[i];
    }
}

bignum calcF(int n,int k){
    if(n == 0) return 1;
    if(F[n][k] != -1) return F[n][k];
    F[n][k] = mul(calcF(n - 2, k - 1), 3);
    for(int i = 2;i<n;i+=2){
        F[n][k] = add(F[n][k], mul(calcF(i, k), calcF(n - i, k)));
    }
    return F[n][k];
}

bignum calcG(int left, int right,int k){
    if(G[left][right][k] != -1) 
        return G[left][right][k];

    if(k == 0){
        return left > right;
    }
    if(left > right){
        return 1;
    }

    if(left + 1 == right){
        long long res = ord[s[left]] / 2;
        if(ord[s[left]] % 2 && ord[s[right]] >= ord[closed[s[left]]])
            res++;
//        printf("left = %d, right = %d, res = %lld\n", left, right, res);
        return G[left][right][k] = res;
    }

    int max_first_open_bracket = ord[s[left]];
    bignum res(0);
    for(int i = 1;i<=max_first_open_bracket;i+=2){
        char close_bracket = closed[brack[i]];
        for(int t = left + 1;t<=right;t+=2){
            if(ord[s[t]] >= ord[close_bracket]){
                res += (calcG(left + 1, t - 1, k - 1) - 1) * calcF(right - t, k) + calcG(t + 1, right, k);
            }
        }
    }
//    printf("left = %d, right = %d, res = %lld\n", left, right, res);
    return G[left][right][k] = res;
}

int main(){
    ios::sync_with_stdio(0);
    int n, k;
    while(cin >> n >> k){
        cin >> s;
        memset(F, 255, sizeof F);
        memset(G, 255, sizeof G);
        ord['('] = 1;
        ord[')'] = 2;
        ord['['] = 3;
        ord[']'] = 4;
        ord['{'] = 5;
        ord['}'] = 6;

        brack[1] = '(';
        brack[2] = ')';
        brack[3] = '[';
        brack[4] = ']';
        brack[5] = '{';
        brack[6] = '}';

        closed['('] = ')'; 
        closed['['] = ']'; 
        closed['{'] = '}'; 
        cout << calcG(0, n - 1, k) << endl;
    }
    return 0;
}
