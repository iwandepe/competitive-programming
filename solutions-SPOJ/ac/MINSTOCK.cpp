#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
int i,j,k;

int main()
{
	priority_queue<pis, vector<pis>, greater<pis>> pq;
	map<string, int> mp;
	int n;
	cin >> n;
	for (i=1;i<=n; i++)
	{
		string b;
		int a, c;
		cin >> a;
		if (a==1){
			cin >> b >> c;
			pq.push(make_pair(c,b));
			mp[b] = c;
		}
		else if(a==2){
			cin >> b >> c;
			pq.push(make_pair(c,b));
			mp[b] = c;
		}
		else{
			cin >> b;
			while (pq.top().first != mp[pq.top().second])
				pq.pop();
			cout << pq.top().second << " " << i << endl;
			pq.pop();
		}
	}
	return 0;
}
