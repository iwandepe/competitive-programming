#include <stdio.h>

main(){
    int n,a,b,c,i,j,k;
    int jj, kk;
    scanf("%d", &n);

    for (i=0;i<n;i++){
        scanf("%d%d%d", &a, &b, &c);
        a=a*c*2;
        b=b*c*2;
        for (j=1;j<=a;j++){
            jj=j%(2*c);
            for (k=1;k<=b;k++){
               kk=k%(2*c);


               if (jj+kk==c+1 || jj+kk==3*c+1){
                    printf("/");
               }
               else if(kk-jj==c || jj-kk==c){
                    printf("\\");
               }
               else{
                    if (c==1&&(jj==0||kk==0)){
                        printf("/");
                    }
                    else{
                        if (jj<=c && jj+kk>c+1 && kk-jj<c){
                            printf("*");
                        }
                        else if(jj>=c && jj+kk<3*c+1 && jj-kk<c){
                            printf("*");
                        }
                        else{
                            printf(".");
                        }
                    }
               }
            }
            printf("\n");
        }
    }
}

