#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++){
        int a,b,hasil,save,digit=0;
        scanf("%d%d", &a, &b);
        while (a>0 || b>0){
            int pengali = 1;
            save = (a%10) + (b%10);
            for (int j=1; j<=digit; j++)
                pengali *= 10;
            hasil = hasil + save*pengali;
        }
        printf("%d", hasil);
    }
}
