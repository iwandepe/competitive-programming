#include<bits/stdc++.h> 
  
using namespace std; 

int unboundedKnapsack(int k, int val[])
{
 	int result[k+1];
 	
 	for (int i=1; i<=k; i++){
 		result[i] = val[i];
	}
 	
 	for (int i=2; i<=k; i++){
 		for (int j=1; j<i; j++){
 			if (val[j] == -1 || result[i-j] == -1)
 				continue;
			if (result[i] == -1)
				result[i] = result[i-j] + val[j];
 			else
 				result[i] = min(result[i], result[i-j] + val[j]);
		 }
	}
    return result[k];
}
  
int main() 
{ 
    int c;
    cin >> c;
    while (c--){
    	int n,k;
    	cin >>n>>k;
    	int arr[k+1];
    	for (int i=1; i<=k; i++){	
    		cin >> arr[i];
		}
		cout << unboundedKnapsack(k,arr) << endl;
	}
    return 0; 
} 
