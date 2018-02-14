#include<bits/stdc++.h>
using namespace std;
int m=1000000007;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		unsigned long long int k,a,b;
		cin>>k>>a>>b;
		unsigned long long int srt=1;
		unsigned long long int mul=1;
		vector<unsigned long long int> vec;
		vec.push_back(srt);
		while(1)
		{
			unsigned long long int qw=srt;
            srt=k*srt+1;
            if(srt>b || srt>1000000000000000000 || qw>srt)
            {
            	break;
            }
            vec.push_back(srt);

		}
		
		unsigned long long int res=0;
		unsigned long long int sum=0;
		bool flag=0;
		for(int i=0;i<vec.size();i++)
		{
            if(i>0)
			sum=(sum%m+vec[i-1]%m)%m;
            if(vec[i]>a)
            {
            	flag=1;
            	if(vec[i-1]>a)
            	res=(res%m+(sum*(vec[i]-vec[i-1])%m)%m)%m;
                else
                res=(res%m+(sum*(vec[i]-a)%m)%m)%m;	
            }
		}
		sum=(sum%m+vec[vec.size()-1]%m)%m;
        if(flag==1)
        {
		
		res=(res%m+(sum*(b-vec[vec.size()-1]+1)%m)%m)%m;
		cout<<res<<endl;
	}
	else
	{
        res=(res%m+(sum*(b-a+1)%m)%m)%m;
        cout<<res<<endl;
	}

	}
	return 0;
}