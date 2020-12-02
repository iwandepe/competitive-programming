#include <stdio.h>
#include <string.h>
void swap(char *a, char *b)
{
	char c = *a;
	*a = *b;
	*b = c;
}

void sort(char arr[], int n)
{
	int i, j, swapped;
	for (i=0; i<n+1; i++) {
		swapped = 0;
		for (j=0; j<n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
				swapped = 1;
			}
		}
		if (swapped == 0){
			break;
		}
	}
}

int main(){
    int t;
    char str[500];
    scanf("%d", &t);
    for (int i=0; i<t; i++){
        scanf(" %s", str);
        int j=0, k=0, len=strlen(str);
        char hasil[len];
        if (len == 1){
            printf("%c\n", str[j]);
            continue;
        }
        while (j<len-1){
            if (str[j] != str[j+1]){
                hasil[k] = str[j];
                if (j == len-2){
                    hasil[k+1] = str[j+1];
                    k+=2;
                    break;
                }
                j++;
                k++;
            }
            else{
                j+=2;
                if (j==len-1){
                    hasil[k] = str[j];
                    k++;
                }
            }
        }

        //SORTING
        if (k == 0){
            printf("\n"); continue;
        }

        sort(hasil, k);
        printf("%c", hasil[0]);
        for (int j=1; j<k; j++){
            if (hasil[j] != hasil[j-1])
                printf("%c", hasil[j]);
        }
        printf("\n");
    }
}
