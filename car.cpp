
#include <iostream>
#include <algorithm>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const int N = 1e4;

struct car{
    int a,b,pos;
};

car cars[N];

bool cmp(car x,car y){
    return ((x.a + y.a) * x.b + y.a * y.b < (x.a + y.a) * y.b + x.a * x.b);
}

int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        long long sum = 0;
        for(int i = 0;i<n;i++){
            cin >> cars[i].a;
            cars[i].pos = i;
            sum += cars[i].a;
        }
        for(int i = 0;i<n;i++){
            cin >> cars[i].b;
        }
        sort(cars, cars + n, cmp);
        long long res = 0;
        for(int i = 0;i<n;i++){
            res = res + sum * cars[i].b;
            sum -= cars[i].a;
        }
        cout << res << endl;
        for(int i = 0;i<n;i++){
            cout << cars[i].pos + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
