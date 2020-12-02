#include <stdio.h>

main(){
	int n,i;

	int inp[10];
    scanf("%d", &n);

    while (n!=0){
        int a=0,b=0,c=0,d=0;
        int out[10]={};
        for (i=2;i>=0;i--){
            inp[i]=n%10;
            n=n/10;
        }

        a=inp[0]*inp[1];
        b=inp[2]*inp[1];

        for (i=1;i>=0;i--){
            out[i]=a%10;
            a=a/10;
        }
        for (i=3;i>=2;i--){
            out[i]=b%10;
            b=b/10;
        }
        c=out[1]+out[3];
        d=out[0]+out[2];

        out[4]=c;
        if (d>=10){
            for (i=5;i<=6;i++){
                out[i]=d%10;
                d=d/10;
            }
            for (i=0;i<7;i++){
                printf("%d", out[i]);
            }
        }
        else{
            out[5]=d;
            for (i=0;i<6;i++){
                printf("%d", out[i]);
            }
        }

        printf("\n");
        scanf("%d", &n);
    }
}
