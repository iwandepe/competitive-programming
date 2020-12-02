/*
#disjoint set

penyelessaian menggunakan disjoint set dan STL (multiset)
*/

#include <bits/stdc++.h>
using namespace std;

int arr[100005], size[100005];
multiset <int> ms;

int root(int i)
{
	while(arr[i] != i)
		arr[i] = arr[arr[i]], i = arr[i];
		
	return i;
}

void join(int A ,int B)
{
    arr[root(B)] = root(A);
}

int main()
{
	int N, Q, A, B;
	cin >> N >> Q;
	for (int i=1; i<=N; i++)
		arr[i] = i, size[i]=1, ms.insert(1);
	
	while (Q--)
	{
		multiset<int>::iterator it;
		cin >> A >> B;
		int root_A = root(A);
		int root_B = root(B);
 		if (root_A != root_B){
 			ms.erase(ms.find(size[root_A]));
 			ms.erase(ms.find(size[root_B]));
 			size[root_A] += size[root_B];
 			size[root_B] = 0;
 			ms.insert(size[root_A]);
 			join(A, B);
		}
		it = ms.end();
		it--;
		cout << *it - *ms.begin() << endl;
	}
	return 0;
}
