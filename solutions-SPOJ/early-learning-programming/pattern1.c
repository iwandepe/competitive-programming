#include <stdio.h>

main(){
    int n,a,b,i,j,k;

    scanf("%d", &n);

    for (i=0;i<n;i++){
        scanf("%d%d", &a, &b);
        for(j=0;j<a;j++){
            for(k=0;k<b;k++){
                if(j%2!=0){
                    k+=1;
                }

                if(k%2==0){
                    printf("*");
                }
                else{
                    printf(".");
                }

                if(j%2!=0){
                    k-=1;
                }
            }
            printf("\n");
        }
    }
}
