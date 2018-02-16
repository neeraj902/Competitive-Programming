#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x,k;
        cin>>n>>m>>x>>k;
        string st;
        cin>>st;
        int ec=0,oc=0;
        for (int i = 0; i < st.length(); ++i)
        {
            if(st[i]=='E') ec++;
            else oc++;
        }
        for (int i = 1; i <=m; ++i)
        {
            if(i%2==0)
            {
                if(x<=ec) 
                    {n-=x; ec-=x;
                    }
                    else
                    {
                        n-=ec;
                        ec=0;
                    }    
 
            }
            else
            {
                  if(x<=oc) 
                    {n-=x; oc-=x;
                    }
                    else
                    {
                        n-=oc;
                        oc=0;
                    }    
            }
        }
        if(n<=0) cout<<"yes\n";
        else cout<<"no\n";
 
    }
    return 0;
} 