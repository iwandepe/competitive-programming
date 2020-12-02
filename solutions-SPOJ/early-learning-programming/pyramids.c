#include <stdio.h>
#include <math.h>

int main()
{
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		double u,v,w,U,V,W;
		scanf("%lf%lf%lf%lf%lf%lf", &U,&V,&w,&W,&v,&u);
		// printf("%lf %lf %lf %lf %lf %lf\n", ab,ac,ad,bc,bd,cd);
		//bagian
		double ux = v*v + w*w - U*U;
        double vx = w*w + u*u - V*V;
        double wx = u*u + v*v - W*W;

        double volume = 1 * sqrt(4*u*u*v*v*w*w - u*u*ux*ux - v*v*vx*vx - w*w*wx*wx + ux*vx*wx) / 12;
		printf("%.4lf\n", volume);
	}

	return 0;
}
