#include <stdio.h>
#include <math.h>
int main(){
    int n;
    scanf("%d", &n);
    int i=sqrt(n),panjang=n,lebar=1;
    while(i>0){
        if (n%i == 0){
            panjang=i;
            lebar=n/i;
            break;
        }
        else
            i--;
    }
    printf("%d\n", panjang*2 + lebar*2);
}
