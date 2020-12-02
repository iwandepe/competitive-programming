#include <stdio.h>

void point(int *xmin,int *ymin,int *xmax, int *ymax);
void circle(int *xmin,int *ymin,int *xmax, int *ymax);
void line(int *xmin,int *ymin,int *xmax, int *ymax);

int t, n, x1, y1, x2, y2, r, i, j, k;
int xmin=-1000,ymin=-1000,xmax=1000,ymax=1000;
char karakter;

main(){
    scanf("%d", &t);
    for (i=0;i<t;i++){
        scanf("%d", &n);
        for (j=0;j<n;j++){
            scanf("%c", &karakter);
            if (karakter=='p'){
                point(xmin,ymin,xmax,ymax);
            }
            else if(karakter=='c'){
                circle(xmin,ymin,xmax,ymax);
            }
            else{
                line(xmin,ymin,xmax,ymax);
            }
        }
        printf("\n");
    }
}

void point(int *xmin,int *ymin,int *xmax, int *ymax){
    scanf("%d%d", &x1, &y1);
    printf("%d%d%d%d", x1,y1,x1,y1);
}

void circle(int *xmin,int *ymin,int *xmax, int *ymax){
    scanf("%d%d%d", &x1, &y1, &r);
    xmin=x1-r;
    ymin=y1-r;
    xmax=y1+r;
    ymax=y2+r;
    printf("%d%d%d%d", xmin,ymin,xmax,ymax);
}

void line(int *xmin,int *ymin,int *xmax, int *ymax){
    scanf("%d%d%d%d", &x1, &y1, &x2, &x2);
    if (x1<=x2){
        xmin=x1;
        xmax=x2;
    }
    else{
        xmin=x2;
        xmax=x1;
    }

    if (y1<=y2){
        ymin=y1;
        ymax=y2;
    }
    else{
        ymin=y2;
        ymax=y1;
    }
    printf("%d%d%d%d", xmin,ymin,xmax,ymax);
}
