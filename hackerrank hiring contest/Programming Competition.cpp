#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	map<int,string> mp;
	for (int i = 0; i < n; ++i)
	{
		string s;
		int a,b;
		cin>>s>>a>>b;
		mp.insert(pair<int,string>(b-a,s));

	}
	map<int,string>::iterator it=(--mp.end());
	cout<<(*it).second<<" "<<(*it).first<<endl;
	return 0;
}