#include <stdio.h>

main(){
    int n,a,b,c,d,i,j,k;

    scanf("%d", &n);

    for (i=0;i<n;i++){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        a=a*(c+1)+1;
        b=b*(d+1)+1;
        for (j=0;j<a;j++){
            for (k=0;k<b;k++){
                 if(j%(c+1)==0){printf("*");}else{
                    if (k%(d+1)==0){printf("*");}else{
                        printf(".");
                    }
                }
            }
            printf("\n");
        }
    }
}
