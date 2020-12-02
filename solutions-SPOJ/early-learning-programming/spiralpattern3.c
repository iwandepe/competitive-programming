#include <stdio.h>

void printSpiral();
void isiSpiral();
void pointer();
void arahPointer();

int n, i, j, k;;
int baris, kolom, batas, penanda, ganti, pindah, ubah, ukuran;
int tandaArah;
int penanda_lanj;
char matrik[101][101];

main(){
	scanf("%d", &n);
	for (i=0;i<n;i++){
		isiSpiral();
		printSpiral();
	}
}

void isiSpiral(){
	scanf("%d", &ukuran);

	for(j=1;j<=ukuran;j++){
        for (k=1;k<=ukuran;k++){
            matrik[j][k]='.';
        }
	}

    baris=1, kolom=0;
	batas=ukuran-1;
	penanda=0, ganti=1;
	pindah=1, tandaArah=1;

	while (batas>1){
		pointer();
		printf("%d-%d\n", baris, kolom);
		matrik[baris][kolom]='*';

		if (penanda==batas){
			penanda=0;
			if (ganti==3){
				ganti=0;
				batas-=2;

				if (batas>1){
					arahPointer();
					for (i=1;i<=batas;i++){
						pointer();
						printf("%d-%d\n", baris, kolom);
						matrik[baris][kolom]='*';
					}

					arahPointer();
					for (i=1;i<=2;i++){
						pointer();
						printf("%d-%d\n", baris, kolom);
						matrik[baris][kolom]='*';
					}
				}
			}
			arahPointer();
			if (batas>1){
				if (ganti==0){
					if (tandaArah==1)
					{
						tandaArah=2;
					}
					else{
						tandaArah=1;
					}
					batas-=2;
				}
			}

			ganti++;
		}
		penanda++;
	}

	if(batas==1){
        pointer();
        matrik[baris][kolom]='*';
	}
}

void pointer(){
	switch (pindah){
			case 1 : kolom+=1; break;
			case 2 : baris+=1; break;
			case 3 : kolom-=1; break;
			case 4 : baris-=1;
		}
}

void arahPointer(){
	if (tandaArah==1){
		switch (pindah){
			case 1 : pindah=2; break;
			case 2 : pindah=3; break;
			case 3 : pindah=4; break;
			case 4 : pindah=1;
		}
	}
	else{
		switch (pindah){
			case 1 : pindah=4; break;
			case 2 : pindah=1; break;
			case 3 : pindah=2; break;
			case 4 : pindah=3;
        }
    }
}

void printSpiral(){
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
