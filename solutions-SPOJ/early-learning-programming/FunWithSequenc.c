#include <stdio.h>

main(){
    int i,j,k, nS,nQ;
    scanf("%d", &nS);
    int S[nS];
    for (i=0;i<nS;i++){
        scanf("%d", &S[i]);
    }
    scanf("%d", &nQ);
    int Q[nQ];
    for (i=0;i<nQ;i++){
        scanf("%d", &Q[i]);
    }
    for (i=0;i<nS;i++){
        k=0;
        for (j=0;j<nQ;j++){
            if (S[i]==Q[j]){
                k++;
            }
        }
        if(k==0) printf("%d ", S[i]);
    }
    printf("\n");
}
