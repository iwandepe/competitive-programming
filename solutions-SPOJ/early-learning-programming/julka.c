#include <stdio.h>
#include <string.h>
int main()
{
    for (int t=0; t<10; t++){
        char jumlah[100], selisih[100];
        int claudia[100], natalie[100];
        scanf("%s%s", &jumlah, &selisih);
        int len = strlen(jumlah); int i = len-1;
        int nel = strlen(selisih); int j = nel-1;
        int k=0;
        // natalie disimpan dari belakang
        while (i>=0 || j>=0){
            if (j<0){
                if (jumlah[i] - '0' < 0){
                    jumlah[i-1]--;
                    natalie[k] = jumlah[i] - '0' + 10;
                }
                else
                    natalie[k] = jumlah[i] - '0';
            }
            else{
                if (jumlah[i] - selisih[j] < 0){
                    jumlah[i-1]--;
                    natalie[k] = jumlah[i] - selisih[j] + 10;
                }
                else
                    natalie[k] = jumlah[i] - selisih[j];
            }
            i--; j--; k++;
        }

        int start_natalie = k-1;
        while (natalie[start_natalie] == 0){
            natalie[start_natalie] = '\0';
            start_natalie--;
        }

//        for (i=start_natalie; i>=0; i--)
//            printf("%d", natalie[i]);
//        printf("\n");

        int temp[k], len_natalie = start_natalie+1, save = 0;
        k = start_natalie;
        i = 0;
        while (k >= 0){
            natalie[k] = natalie[k] + save;
            if (natalie[k]/2 > 0){
                temp[i] = natalie[k]/2;
                save = (natalie[k] - temp[i]*2) * 10;
            }
            else{
                if (natalie == 0) temp[i] = 0;
                else  save = natalie[k] + 10;
            }
//            printf("%d = %d\n", k, temp[i]);
            k--; i++;
        }

        // temp menggantikan natalie dan sudah tersimpan urut dari depan
//        for (i=0; i<len_natalie; i++)
//            printf("%d", temp[i]);
//        printf("\n");

        int l = 0;
        save = 0;
        k = start_natalie; // pointer natalie/temp sekaligus claudia yang akan dicari
        i = nel - 1; // pointer selisih
        while (k>=0 || i>=0){
            if (k < 0){
                save = save + temp[i] - '0';
                claudia[l] = save%10;
                save = save/10;
            }
            else if (i < 0){
                save = save + temp[k];
                claudia[l] = save%10;
                save = save/10;
            }
            else{
                save = save + temp[k] + selisih[i] - '0';
                claudia[l] = save%10;
                save = save/10;
            }
            l++; k--; i--;
        }
        if (save>0) printf("%d", save);
        for (i=l-1; i>=0; i--)
            printf("%d", claudia[i]);
        printf("\n");
        for (i=0; i<len_natalie; i++)
            printf("%d", temp[i]);
        printf("\n");
    }
}
