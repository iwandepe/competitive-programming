#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int arr[10005];
	cin >> n;
	while (n){
		for (int i=0; i<n; i++)
			cin >> arr[i];
			
		int max=0, temp=0;
		for (int i=0; i<n; i++){
			temp += arr[i];
			if (max < temp)
				max = temp;
			if (temp < 0)
				temp = 0;
		}
		
		if (max > 0)
			cout << "The maximum winning streak is " << max <<"." << endl;
		else 
			cout << "Losing streak." << endl;
		
		cin >> n;
	}
	return 0;
}
