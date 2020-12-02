#include <bits/stdc++.h>
using namespace std;

int main(){
//	freopen("CUBES.txt", "w", stdout);
	int a,b,c,d;
	for (a=6; a<=100; a++){
		for (b=2; b<=100; b++){
			for (c=b; c<=100; c++){
				for (d=c; d<=100; d++){
					if (pow(a,3)==pow(b,3)+pow(c,3)+pow(d,3))
						cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")\n"; 
				}
			}
		}	
	}
//	fclose(stdout);
	return 0;
}
