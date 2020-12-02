#include <stdio.h>

main(){
    int n,a,b,i,j,k;

    scanf("%d", &n);

    for (i=0;i<n;i++){
        scanf("%d%d", &a, &b);
        for (j=0;j<a;j++){
            for (k=0;k<b;k++){
                if (j==0||j==a-1){
                    printf("*");
                }else{
                    if (k==0||k==b-1){
                        printf("*");
                    }else{
                        printf(".");
                    }
                }

            }
            printf("\n");
        }
    }
}
