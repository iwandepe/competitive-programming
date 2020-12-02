#include <stdio.h>

main(){
	int n, i, ukuran, j, k;;
	int baris, kolom, batas, penanda, ganti, pindah;
	char matrik[101][101];

	scanf("%d", &n);

	for (i=0;i<n;i++){
		scanf("%d", &ukuran);
		for(j=1;j<=ukuran;j++){
            for (k=1;k<=ukuran;k++){
                matrik[j][k]='.';
            }
		}
        baris=0, kolom=1;
		batas=ukuran-1;
		penanda=0, ganti=0;
		pindah=1;

		while (batas>1){
			switch (pindah){
				case 1 : baris+=1; break;
				case 2 : kolom+=1; break;
				case 3 : baris-=1; break;
				case 4 : kolom-=1;
			}

            matrik[baris][kolom]='*';

			if (penanda==batas){
				penanda=0;
				if (ganti==2){
					ganti=0;
					batas-=2;
				}

				switch (pindah){
					case 1 : pindah=2; break;
					case 2 : pindah=3; break;
					case 3 : pindah=4; break;
					case 4 : pindah=1;
				}
				ganti++;
			}
			penanda++;
		}
		if(batas==1){
            switch (pindah){
				case 1 : baris+=1; break;
				case 2 : kolom+=1; break;
				case 3 : baris-=1; break;
				case 4 : kolom-=1;
			}
            matrik[baris][kolom]='*';
		}

		for (baris=1;baris<=ukuran;baris++){
			for (kolom=1;kolom<=ukuran;kolom++){
				if (matrik[baris][kolom]=='*'){
					printf("*");
				}
				else{
					printf(".");
				}
			}
			printf("\n");
		}
	}
}
