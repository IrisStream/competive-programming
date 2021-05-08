#include <algorithm>
#include <stdio.h>

const int N = 1e3;

int a[N][N];
int F[N];
int d[N][N];

int main(){
    int n,m;
    scanf("%d%d", &n,&m);
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            scanf("%d", &a[i][j]);
            d[i][a[i][j]] = j;
        }
    }
    int res = 0;
    for(int i = 0;i<n;i++){
        F[i] = 1;
        for(int j = 0;j<i;j++){
            bool ordered = true;
            for(int k = 1;k<m;k++){
                if(d[k][a[0][j]] > d[k][a[0][i]]){
                    ordered = false;
                    break;
                }
            }
            if(ordered) {
                if(F[i] < F[j] + 1)
                    F[i] = F[j] + 1;
            }
        }
        if(res < F[i])
            res = F[i];
    }
    printf("%d\n", res);
    return 0;
}
