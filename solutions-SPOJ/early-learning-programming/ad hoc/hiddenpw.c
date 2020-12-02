#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char kode[6];
}kode_t;

int main() {
    int t,i,j,n,k;
    int a,b;
    kode_t str[100];
    char str2[64];
    scanf("%d", &t);
    for (i=0; i<t; i++) {
        scanf("%d", &n);
        for (j=0; j<n; j++){
            scanf(" %s", str[j].kode);
        }
        
        scanf(" %s", str2);
        for (j=0; j<n; j++){
            a=0;b=0;
            for (k=0; k<6; k++){
                a = a + (((str[j].kode[k] >> k) % 2) << k);
                b = b + (((str[j].kode[k] >> ((k+3)%6)) % 2) << k);
                printf("a = %d\n", a);
            }
            // printf("%d ", a);
            // printf("%d ", b);    
            printf("%c", str2[a]);
            printf("%c", str2[b]);
        }
        printf("\n");
    }
    return 0;
}