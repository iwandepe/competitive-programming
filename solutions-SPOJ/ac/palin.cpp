#include <bits/stdc++.h>
using namespace std;

int all_nine(string num, int len){
	for (int i=0; i<len; i++)
	{
		if (num[i]=='9') continue;
		else return 0;
	}
	return 1;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		string num;
		cin >> num;
		int len=num.length(),i,j;
		char res[len+3];
		if (all_nine(num, len))
		{
			res[0]='1';
			for (i=1; i<len; i++)
				res[i] = '0';
			res[i] = '1';
			res[i+1] = '\0';
			cout << res << endl;
		}
		else
		{
			i=len/2;
			j=i;
			
			if (len%2==0) 
				i--;
			
			while (i>=0 && num[i]==num[j])
			{
				i--;
				j++;
			}
			if (i<0 || num[i]<num[j])
			{
				i=len/2;
				j=i;
				
				if (len%2==0)
					i--;
				
				int temp = 1;
				while(i>=0)
				{
					temp = (num[i]-'0')+temp;
					num[i] = temp%10 +'0';
					num[j] = num[i];
					temp = temp/10;
					i--;
					j++;
				}
			}
			else
			{
				while (i>=0)
				{
					num[j] = num[i];
					i--;
					j++;
				}
			}
			cout << num << endl;
			
		}
	}
}
