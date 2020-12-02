#include <stdio.h>

main(){
    int n,a,b,c,d,i,j,k;

    scanf("%d", &n);

    for (i=1;i<=n;i++){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        a=(a*(c+1))+c;
        b=(b*(d+1))+d;
        for (j=1;j<=a;j++){
            for (k=1;k<=b;k++){
                if (j%(c+1)==0){
                    if (k%(d+1)==0){
                        printf("+");
                    }
                    else{
                        printf("-");
                    }
                }
                else{
                    if (k%(d+1)==0){
                        printf("|");
                    }
                    else{
                        printf(".");
                    }
                }
            }
            printf("\n");
        }
    }
}

