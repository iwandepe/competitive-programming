#include <stdio.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++){
        char a[10], b[10], besar[10], kecil[10];
        scanf(" %s", a);
        scanf(" %s", b);
        int lena = strlen(a), lenb = strlen(b);
        for (int j=lena-1; j>=0; j--){
            if (a[j]=='0' ){
                a[j]='\n';
                lena--;
            }
            else break;
        }
        for (int j=lenb-1; j>=0; j--){
            if (b[j]=='0'){
                b[j]='\n';
                lenb--;
            }
            else break;
        }

        int c, nambah = 0;
        if (lena>=lenb){
            strcpy(besar, a);
            strcpy(kecil, b);
        }
        else{
            strcpy(besar, b);
            strcpy(kecil, a);
            c = lena;
            lena = lenb;
            lenb = c;
        }

        int save = 0, hasil[11];
        for (int j=0; j<lena; j++){
            if (j >= lenb){
                save = save + besar[j]-48;
                hasil[j] = save % 10;
                save = save / 10;
            }
            else{
                save = save + (besar[j]-'0')+(kecil[j]-'0');
                hasil[j] = save%10;
                save = save / 10;
            }

            if (j == lena-1 && save > 0){
                hasil[j+1] = save;
                nambah = 1;
            }
        }

        int angkapenting=0;
        for (int j=0; j<lena; j++){
            if (hasil[j] != 0 || angkapenting == 1){
                printf("%d", hasil[j]);
                angkapenting = 1;
            }
        }
        if (nambah == 1)
            printf("%d", hasil[lena]);
        printf("\n");
    }
}
