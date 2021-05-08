#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <map>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 105;

long long f[N][N];
long long g[N][N][N][2];
map<char, int> ord;
map<char, char> closed;
int brack[7];
string s;

long long calcf(int n,int k){
    if(f[n][k] != -1)
        return f[n][k];
    if(n == 0)
        return f[n][k] = 1;
    if(k == 0)
        return f[n][k] = 0;
    long long res = 0;
    for(int i = 2;i<=n;i+=2){
        res += calcf(i - 2, k - 1) * calcf(n - i, k) * 3;
    }
    return f[n][k] = res;
}

long long calcg(int left, int right, int k, bool isLess){
    if(g[left][right][k][isLess] != -1)
        return g[left][right][k][isLess];

    if(left > right)
        return g[left][right][k][isLess] = 1;

    if(k == 0)
        return g[left][right][k][isLess] = 0;

    long long res = 0;
    if(left == 1 && right == 4)
        cout << "start debug" << endl;
    // Tính số các dãy ngoặc nhỏ hơn s[left .. right]
    long long lower = ord[s[left]] / 2;
    if(lower > 0){
        for(int split = left + 1;split <= right; split+=2){
            res += lower * calcf(split - left - 1, k - 1) * calcf(right - split, k);
        }
    }
    //Tính số các dãy ngoặc có thể  sẽ bằng s[left .. right]
    long long pref = 0;
    if(ord[s[left]] % 2){ //s[left] là mở ngoặc
        char close_bracket = closed[s[left]];
        for(int split = left + 1;split < right;split += 2){
            if(close_bracket < s[split]){
                pref = calcg(left + 1, split - 1, k - 1, isLess);
                if(pref == 0) continue;
                res += (pref - 1) * calcf(right - split, k) + calcg(split + 1, right, k, isLess);
            }
            else if(close_bracket == s[split]){
                //Tính được
                if(isLess){
                    res += calcg(left + 1, split - 1, k - 1, true);
                }
            }
            else{
                //Tính số lượng dãy ngoặc nhỏ hơn
            }
        }
        if(close_bracket <= s[right])
            res += calcg(left + 1, right - 1,k - 1, isLess);
    }
    printf("left = %d, right = %d, k = %d, res = %lld\n", left, right, k, res);
    return g[left][right][k][isLess] = res;
}

void init(){
    memset(f, 255, sizeof f);

    brack[1] = '(';
    brack[2] = ')';
    brack[3] = '[';
    brack[4] = ']';
    brack[5] = '{';
    brack[6] = '}';


    ord['('] = 1;
    ord[')'] = 2;
    ord['['] = 3;
    ord[']'] = 4;
    ord['{'] = 5;
    ord['}'] = 6;

    closed['('] = ')';
    closed['['] = ']';
    closed['{'] = '}';

}

int main(){
    ios::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    init();
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=k;j++){
            calcf(i,j);
        }
    }

    while(cin >> s){
        memset(g, 255, sizeof g);
        cout << s << " " << calcg(0, n - 1, k, false) << endl;
    }


    return 0;
}
