#include <stdio.h>

main(){
    int n,a,b,i,j,k;

    scanf("%d", &n);

    for (i=0;i<n;i++){
        scanf("%d%d", &a, &b);
        a=a*3+1;
        b=b*3+1;
        for (j=0;j<a;j++){
            for (k=0;k<b;k++){
                if(j%3==0){printf("*");}else{
                    if (k%3==0){printf("*");}else{
                        printf(".");
                    }
                }
            }
            printf("\n");
        }
    }
}
