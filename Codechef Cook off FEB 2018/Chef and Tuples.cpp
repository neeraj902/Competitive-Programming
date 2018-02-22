#include<bits/stdc++.h>
using namespace std;
int main()
{
 
    long long int t;
    cin>>t;
    while(t--)
    {
       long long int n,a,b,c;
       cin>>n>>a>>b>>c;
       vector<long long int> veca,vecb,vecc;
       for(long long int i=1;i*i<=n;i++)
       {
          if(n%i==0)
          {
            if(i<=a) veca.push_back(i);
            if(i<=b) vecb.push_back(i);
            if(i<=c) vecc.push_back(i);
            if(i*i!=n)
            {
                if((n/i)<=a) veca.push_back(n/i);
                if((n/i)<=b) vecb.push_back(n/i);
                if((n/i)<=c) vecc.push_back(n/i);
            }
          }
       }  
       sort(veca.begin(),veca.end());
       sort(vecb.begin(),vecb.end());
       sort(vecc.begin(),vecc.end());
       long long int county=0;
       for (long long int i = 0; i<veca.size(); ++i)
       {
            long long int k=vecc.size()-1;
            for(long long int j=0;j<vecb.size();j++)
            {
                 for(k;k>=0;k--)
                 {
                     long long int jkl=veca[i]*vecb[j]*vecc[k];
                     if(jkl==n) {county++; }
                     else if(jkl<n) break;
                 }
            }
       }
       cout<<county<<endl;
 
 
 
    }
    return 0;
} 