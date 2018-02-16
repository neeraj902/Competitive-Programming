#include<bits/stdc++.h>
using namespace std;
int lp;
class gh{
public:
    vector<pair<pair<int,int>,pair<int,int> > > PV;
    vector<int> vec;
    int cur;
    int oc;
    int ec;
    int lw;
    int did;
};
bool comp(pair<int,int> p1,pair<int,int> p2)
{
    if((p1.first)/lp < (p2.first)/lp)
        return true;
    else if((p1.first)/lp > (p2.first)/lp)
        return false;
    else return (p1.second<p2.second);
}
bool comp1(int a,int b)
{
    return a>b;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        lp=sqrt(n);
        pair<int,int> arr1[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>arr1[i].first>>arr1[i].second;
        }
        sort(arr1,arr1+n,comp);
        
 
        vector<gh> arr;
        gh g1;
        g1.did=g1.cur=g1.oc=g1.ec=0;
        arr.push_back(g1);
        int csv=lp-1;
        for (int i = 0; i < n; ++i)
        {
             if(arr1[i].first>csv)
             {
                arr[arr.size()-1].lw=arr[arr.size()-1].PV.size();
                arr.push_back(g1);
                csv+=lp;
             }
             pair<int,int> p;
             p.first=arr1[i].first;
             p.second=arr1[i].second;
             pair<int,int> p1;
             p1.first=0;
             p1.second=0;
             pair<pair<int,int>,pair<int,int> > pi;
             pi.first=p;
             pi.second=p1;
             arr[arr.size()-1].PV.push_back(pi);
 
        }
        arr[arr.size()-1].lw=arr[arr.size()-1].PV.size();
 
        int times=floor(n/lp)+1;
 
       
        int yui=arr.size();
        times-=yui;
        while(times>0)
        {
          g1.lw=0;
          arr.push_back(g1);
          times--;
        }
        
        for (int i = 0; i < arr.size(); ++i)
        {
             arr[i].vec.resize(n+2);
             int index=0;
             for (int j = 0; j <arr[i].PV.size(); ++j)
             {
                   int sumo=arr[i].PV[j].first.second;
                   while(index<=sumo)
                   {
                      arr[i].vec[index]=j;
                      index++;
                   }
             }
             for (int j = index; j <arr[i].vec.size(); ++j)
             {
                 arr[i].vec[j]=-1;
             }
        }
 
        
 
 
        int noofqueries;
        cin>>noofqueries;
        for (int mas = 1; mas<=noofqueries; ++mas)
        {
              int TOC=0;
              int q;
              cin>>q;
              int quer[q];
              for (int i = 0; i < q; ++i)
              {
                   cin>>quer[i];
              }
              sort(quer,quer+q,comp1);
             
              for (int i = 0; i < q; ++i)
              {
                                      int qw=quer[i];
                                      int endpoi=qw/lp-1;
                                      for (int j = 0; j <=endpoi; ++j)
                                      {
                                            int bd=arr[j].vec[qw];
 
                                            if(bd==-1) continue;
                                            if(arr[j].cur!=mas)
                                            {
                                                 arr[j].cur=mas;
                                                 arr[j].oc=arr[j].ec=0;
                                                 arr[j].lw=arr[j].PV.size();
                                            }
                                            TOC-=arr[j].oc;
                                            swap(arr[j].oc,arr[j].ec);
                                            arr[j].oc=(arr[j].lw-bd)+arr[j].oc;
                                            arr[j].lw=bd;
                                            TOC+=arr[j].oc;
                                            if(arr[j].PV[bd].second.second==mas)
                                                arr[j].PV[bd].second.first++;
                                            else
                                            {
                                                arr[j].PV[bd].second.second=mas;
                                                arr[j].PV[bd].second.first=1;
                                            }
                                            
                                      }
 
                                     
 
                                      if(arr[endpoi+1].did!=1)
                                      {
                                          arr[endpoi+1].did=1;
                                          int kth=0;
                                          for (int j = 0; j <arr[endpoi+1].PV.size(); ++j)
                                          {
                                                if(arr[endpoi+1].PV[j].second.second==mas)
                                                    kth+=arr[endpoi+1].PV[j].second.first;
                                                arr[endpoi+1].PV[j].second.first=kth;
                                          }
                                      }
 
                                      
 
                                      for (int j = 0; j <arr[endpoi+1].PV.size(); ++j)
                                      {
                                             int kl=arr[endpoi+1].PV[j].first.first;
                                             int lm=arr[endpoi+1].PV[j].first.second;
                                             if(kl<=qw && qw<=lm)
                                             {
                                                if((arr[endpoi+1].PV[j].second.first)%2==0)
                                                {
                                                    TOC++;
                                                }
                                                else TOC--;
                                                (arr[endpoi+1].PV[j].second.first)++;
                                             }
                                      }
                                      if(i>0)
                                      {
                                        int TSH=qw/lp;
                                        int MSS=(quer[i-1]/lp);
                                        if(TSH!=MSS)
                                        {
                                            arr[MSS].did=0;
                                        }
                                      }
                                      
                    
 
                  
 
              }
              arr[quer[q-1]/lp].did=0;
               
                    
              cout<<TOC<<endl;
        }
 
    }
    return 0;
}  