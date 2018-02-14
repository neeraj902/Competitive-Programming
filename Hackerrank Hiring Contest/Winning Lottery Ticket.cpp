#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;j
	cin>>n;
	int arr[n];
	int county[1024]={0};
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin>>s;
		int res=0;
		for(int j=0;j<s.length();j++)
		{
           int num=s[j]-48;
           res=res|(1<<num);
		}
		arr[i]=res;
		county[arr[i]]++;
	}
	
	long long int result=0;
	for (int i = 1; i <=1022 ; ++i)
	{
		
			for(int j=1;j<=1022;j++)
			{
				if( (j|i)==1023)
				{
					result+=((long long)county[j]*(long long)county[i]);
				}
			}

	}
	result/=2;
	result+=((long long)county[1023]*(long long)(n-county[1023]));
	result+=((long long)county[1023]*(long long)(county[1023]-1))/2;
	cout<<result;

	return 0;
}