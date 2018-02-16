#include<bits/stdc++.h>
using namespace std;
class gh{
public:
    long long int x;
    long long int y;
};
 
long long int foo(long long int srt,vector<gh> vec)
{
    long long int lo=0,hi=vec.size()-1;
    long long int mid=(lo+hi)/2;
    for(long long int i=0;i<20;i++)
    {
        if(vec[mid].y<srt)
        {
            lo=mid;
            mid=(lo+hi)/2;
            continue;
        }
        if(vec[mid].y>srt)
        {
            hi=mid;
            mid=(lo+hi)/2;
            continue;
        }
        if(vec[mid].y==srt)
        {
            return vec[mid].x;
        }
    }
    long long int jkl=srt-vec[lo].y;
    long long int iop=vec[hi].x-vec[lo].x;
    
    long long int ans=((jkl)*(iop))/(vec[hi].y-vec[lo].y)+vec[lo].x;
    return ans;
 
}
 
long long int da(vector<gh>& vec,long long  int n)
{
    
    long long int DA = 0;
 
    
    long long int j = n - 1;
    for (long long int i = 0; i < n; i++)
    {
        DA += (vec[j].x + vec[i].x) * (vec[j].y - vec[i].y);
        j = i;  
    }
    return abs(DA);
}
 
 
 
long long int GBC(gh pq,gh qp)
{
    
    if (pq.x==qp.x)
        return abs(pq.y - qp.y) - 1;
    else if (pq.y == qp.y)
        return abs(pq.x-qp.x) - 1;
 else
    return __gcd(abs(pq.x-qp.x),abs(pq.y-qp.y))-1;
}
 
long long int GIC(vector<gh>& vec)
{
   
    long long int B=0;
    for (long long int i = 0; i < vec.size()-1; ++i)
    {
        B=B+GBC(vec[i],vec[i+1]);
    }
    B+=GBC(vec[vec.size()-1],vec[0]);
    B+=vec.size();
 
    long long int DA=da(vec,vec.size());
    return (DA - B + 2)/2;
 
}
 
 
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        long long int llv=1000000007,ulv=-1000000007,ll,ul;
        cin>>n;
        vector<gh> vec;
        for (long long int i = 0; i < n; ++i)
        {
              gh g1;
              cin>>g1.x>>g1.y;
              vec.push_back(g1);
              if(g1.y<llv) {llv=g1.y; ll=i; }
              if(g1.y>ulv) {ulv=g1.y; ul=i; }
        }
        /*
        long long int nop=GIC(vec);
        if(nop<(n/10)) 
        {
            cout<<"-1\n";
            continue;
        }*/
        vector<gh> vec1;
        vector<gh> vec2;
        if(ul<=ll)
        {
            for (long long int i = ul; i <=ll; ++i)
            {
                vec1.push_back(vec[i]);
            }
            for (long long int i = ll; i <vec.size(); ++i)
            {
                vec2.push_back(vec[i]);
            }
            for (long long int i = 0; i <= ul; ++i)
            {
                vec2.push_back(vec[i]);
            }
        }
        else
        {
            for (long long int i = ll; i <=ul; ++i)
            {
                vec2.push_back(vec[i]);
            }
            for (long long int i = ul; i <vec.size(); ++i)
            {
                vec1.push_back(vec[i]);
            }
            for (long long int i = 0; i <= ll; ++i)
            {
                vec1.push_back(vec[i]);
            }
        }
        reverse(vec1.begin(),vec1.end());
        
        
 
        long long int srt=(vec[ll].y+vec[ul].y)/2,count=0,kl=n/10;
        
        while(1)
        {
            long long int SP=foo(srt,vec1);
            long long int EP=foo(srt,vec2);
            
            for (long long int i = SP+1; i < EP; ++i)
            {
                cout<<i<<" "<<srt<<endl;
                count++;
                if(count==kl) break;
            }
            srt++;
            
            if(count>=kl) break;
 
        }
 
 
        
 
    }
    return 0;
} 