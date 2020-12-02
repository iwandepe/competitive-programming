#include <stdio.h>

main(){
    int n,a,b,c,i,j,k;

    scanf("%d", &n);

    for (i=0;i<n;i++){
        scanf("%d%d%d", &a, &b, &c);
        a=a*(c+1)+1;
        b=b*(c+1)+1;
        for (j=0;j<a;j++){
            for (k=0;k<b;k++){
                if(j%(c+1)==0){
                    printf("*");
                }
                else{
                    if (k%(c+1)==0){
                        printf("*");
                    }
                    else{
                        if((j/(c+1))%2==0 && (k/(c+1))%2==0 || (j/(c+1))%2!=0 && (k/(c+1))%2!=0){
                            if ((j-k)%(c+1)==0){
                                printf("\\");
                            }
                            else{
                                printf(".");
                            }
                        }
                        else{
                            if ((j+k)%(c+1)==0){
                                printf("/");
                            }
                            else{
                                printf(".");
                            }
                        }

                    }
                }
            }
            printf("\n");
        }
    }
}
