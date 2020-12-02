#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main(){
	int n;
	cin >> n;
	int d[n];
	cout << "start" << endl;
	for (int i=0; i<n; i++){
		cin >> d[i];
	}
	int result = accumulate(d, d + n, 1, lcm);
	cout << result << endl;
	return 0;
}
