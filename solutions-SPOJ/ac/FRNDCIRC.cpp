#include <bits/stdc++.h>
using namespace std;

unordered_map <string, string> parent;
unordered_map <string, int> size;

string root(string name)
{
	while (parent[name] != name)
		parent[name] = parent[parent[name]], name = parent[name];
	return name;
}

void join(string a, string b)
{
	parent[root(b)] = root(a);
}

int main()
{
	int t,n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		while (n--)
		{
			string a, b, a_root, b_root;
			cin >> a >> b;
			
			if (parent.find(a) == parent.end())
				parent[a] = a, size[a]=1;
			if (parent.find(b) == parent.end())
				parent[b] = b, size[b]=1;
				
			a_root = root(a);
			b_root = root(b);
			
			if (a_root != b_root){
				size[a_root] += size[b_root];
				size[b_root] = 0;
				cout << size[a_root] << endl;
				join(a, b);
			}
			else{
				cout << size[a_root] << endl;
			}
		}
		parent.clear();
		size.clear();
	}
	return 0;
}
