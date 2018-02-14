#include<bits/stdc++.h>
using namespace std;
int m=1000000007;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	map<int,int> mp;
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		if(mp.find(arr[i])==mp.end())
		{
			mp[arr[i]]=0;
		}
		 if(mp.find(arr[i])!=mp.end())
		 {
             int a=mp[arr[i]-1];
             int b=mp[arr[i]];
             int c=mp[arr[i]+1];
             if(a==b && b==c)
             {
             	ans++;
             	mp[arr[i]]++;
             }
             else if(a<b && c<b)
             {
             	ans++;
             	mp[arr[i]]++;
             }
             else if((a>b && b==c)||(a==b && c>b))
             {
             	mp[arr[i]]++;
             }
             else if((a<b && b==c)||(a==b && c<b))
             {
             	ans++;
             	mp[arr[i]]++;
             }
             else if(a>b && c>b)
             {
             	ans--;
             	mp[arr[i]]++;
             }
             else 
             {
             	mp[arr[i]]++;
             }
		 }
	}
	int q;
	cin>>q;
	int ui=1;
	int res=0;
	while(q--)
	{
		int id,val;
		cin>>id>>val;
		id--;
		int tbd=arr[id];
		{
             int a=mp[tbd-1];
             int b=mp[tbd];
             int c=mp[tbd+1];
             if(a==b && b==c)
             {
             	ans++;
             	mp[tbd]--;
             }
             else if(a<b && c<b)
             {
             	ans--;
             	mp[tbd]--;
             }
             else if((a>b && b==c)||(a==b && c>b))
             {
             	ans++;
             	mp[tbd]--;
             }
             else if((a<b && b==c)||(a==b && c<b))
             {
             	
             	mp[tbd]--;
             }
             else if(a>b && c>b)
             {
             	ans++;
             	mp[tbd]--;
             }
             else 
             {
             	mp[tbd]--;
             }
		 }
		 arr[id]=val;
		 tbd=val;
		 {
             int a=mp[arr[id]-1];
             int b=mp[arr[id]];
             int c=mp[arr[id]+1];
             if(a==b && b==c)
             {
             	ans++;
             	mp[arr[id]]++;
             }
             else if(a<b && c<b)
             {
             	ans++;
             	mp[arr[id]]++;
             }
             else if((a>b && b==c)||(a==b && c>b))
             {
             	mp[arr[id]]++;
             }
             else if((a<b && b==c)||(a==b && c<b))
             {
             	ans++;
             	mp[arr[id]]++;
             }
             else if(a>b && c>b)
             {
             	ans--;
             	mp[arr[id]]++;
             }
             else 
             {
             	mp[arr[id]]++;
             }
		 }
		 res=(res%m+((long long)ui%m*(long long)ans%m)%m)%m;

     ui++;
	}
	cout<<res;

	return 0;
}