#include<stdio.h>

int bil(int N)
{
    if (N==0) return 0;
    return (pow(N,2)+bil(N-1));
}

int main()
{
    int N;
    scanf("%d", &N);
    printf("%d\n", bil(N));
    return 0;
}
