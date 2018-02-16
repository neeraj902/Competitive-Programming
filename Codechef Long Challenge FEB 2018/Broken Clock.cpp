#include<bits/stdc++.h>
using namespace std;
long long int m=1000000007;
 
bool ispowert(long long int jk)
{
    long long int jkl=(long long)log2(jk);
    if(pow(2,jkl)==jk) return true;
    else return false;
}
 
long long int gol(long long int aqw,long long int bwq,long long int *xt,long long int *yt)
{
    
    if (aqw == 0)
    {
        *xt = 0, *yt = 1;
        return bwq;
    }
 
    long long int x123, y123; 
    long long int gcd = gol(bwq%aqw, aqw, &x123, &y123);
 
    
    *xt = y123 - (bwq/aqw) * x123;
    *yt = x123;
 
    return gcd;
}
 
 
 
long long int qwert(long long int l,long long int m)
{
    long long int x, y;
    long long int g = gol(l, m, &x, &y);
   
    {
        
        long long int res = (x%m + m) % m;
        return res;
    }
  
}
 
 
class gh
{
public:
    long long int a;
    long long int b;
};
 
 
 
 
 
gh foo(gh g1,long long int iml,long long int d,long long int l,long long int jkl)
{
    if(g1.a==0 && g1.b==1)
    {
        gh g2;
        g2.a=1;
        g2.b=jkl;
        return g2;
    }
    gh g2;
    long long int kl=min(g1.a,g1.b);
    g2.a=kl/2;
    g2.b=kl/2+1;
    if(g2.a%2==1)  swap(g2.a,g2.b);
    gh g3=foo(g2,iml,d,l,jkl);
    gh g4;
    if((g1.a/2)%2==1)
    {
        g4.a=(((2%m*g3.b%m)*g3.b%m)%m-1)%m;
        if(g4.a<0) g4.a+=m;
    }
    else
    {
        g4.a=(((2%m*g3.a%m)*g3.a%m)%m-1)%m;
        if(g4.a<0) g4.a+=m;
    }
        g4.b=(((2%m*g3.a%m)*g3.b%m)%m-jkl)%m;
        if(g4.b<0) g4.b+=m;
        return g4;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int l,d,t;
        cin>>l>>d>>t;
        long long int iml=qwert(l,m);
        
        {
            gh g1;
            if(t%2==0)
            {
                g1.a=t;
                g1.b=t-1;
                gh g2=foo(g1,iml,d,l,(d%m*iml%m)%m);
                cout<<((g2.a)%m*(l%m))%m<<endl;
            }
            else
            {
                g1.a=t-1;
                g1.b=t;
                gh g2=foo(g1,iml,d,l,(d%m*iml%m)%m);
                cout<<((g2.b)%m*(l%m))%m<<endl;
            }
            
         
          continue;
        }
        
    }
    return 0;
} 