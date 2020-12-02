#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N, x;
	cin >> N;
	priority_queue <int> akik;
	while (N--)
	{
		cin >> x;
		if (x==1){
			int harga;
			cin >> harga;
			akik.push(harga);
		}
		else if (x==2){
			cout << akik.top() << endl;;
		}
		else{
			akik.pop();
		}
	}
	return 0;
}
