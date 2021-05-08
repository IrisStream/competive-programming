#include <stdio.h>

int main(){
    int * f = new int[16];
    f[0] = 1;
    f[1] = 3;
    int sum = 4;
    for(int i = 2;i<16;i++){
        f[i] = sum * 2 + f[i-1];
        sum += f[i];
    }

    int n;
    while(true){
        scanf("%d", &n);
        if(n < 0)
            break;
        if(n % 2)
            printf("0\n");
        else
            printf("%d\n", f[n >> 1]);
    }
    return 0;
}
