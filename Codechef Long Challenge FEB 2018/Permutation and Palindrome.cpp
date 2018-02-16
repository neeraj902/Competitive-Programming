#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vector<int> arr[26];
        int numofodds=0;
        for (int i = 0; i < s.length(); ++i)
        {
             arr[s[i]-97].push_back(i);
        }
        int op;
        for (int i = 0; i < 26; ++i)
        {
            int kl=arr[i].size();
            if(kl%2==1) { numofodds++; op=i;}
        }
        int ans[s.length()];
        if(numofodds>1)
        {
            cout<<"-1\n";
            continue;
        }
        else if(numofodds==1)
        {
            int hj=s.length();
            ans[hj/2]=arr[op][arr[op].size()-1]+1;
            arr[op].pop_back();
        }
        int ind1=0,ind2=s.length()-1,covered=0;
        for (int i = 0; i < 26; ++i)
        {
              int lk=0,kl=arr[i].size()-1;
              while(lk<kl)
              {
                 ans[ind1]=arr[i][lk]+1;
                 ans[ind2]=arr[i][kl]+1;
                 lk++; kl--;
                 ind1++;
                 ind2--;
 
              }
        }
        for (int i = 0; i < s.length(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
} 