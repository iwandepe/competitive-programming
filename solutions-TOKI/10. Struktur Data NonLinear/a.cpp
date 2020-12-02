#include <bits/stdc++.h>
using namespace std;

int Arr[100005];
int size[100005];

void init(int N)
{
    for(int i = 1; i<=N; i++)
    {
        Arr[ i ] = i ;
        size[i] = 1;
    }
}

int root(int i)
{
    while(Arr[ i ] != i) 
    {
     i = Arr[ i ];
    }
    return i;
}


bool cek(int A,int B)
{
    if( root(A)==root(B) )  
        return true;
    else
        return false;
}

void join(int A ,int B)
{
    int root_A = root(A);
    int root_B = root(B);
    if (size[root_A] < size[root_B])
    {
    	Arr[root_A] = Arr[root_B];
    	size[root_B] += size[root_A];
	}
	else
	{
		Arr[root_B] = Arr[root_A];
    	size[root_A] += size[root_B];
	}
}

int main()
{
    int n,q,x,a,b;
    cin >> n >> q;
    init(n);
    for (int i=0; i<q; i++)
    {
        cin >> x >> a >> b;
        if (x==1)
            join(a, b);

        else if (cek(a, b))
            cout << "Y" << endl;

        else
            cout << "T" << endl;
    }
    return 0;
}
