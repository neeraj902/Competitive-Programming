#include <iostream>
#include <vector>
#include<algorithm>
#include<bits/stdc++.h>
 
using namespace std;
unsigned long long dfghjkl(vector<unsigned long long int > &v, unsigned long long int  lty, unsigned long long int r, unsigned long long int  key);
unsigned long long int qwertyuiop(vector<unsigned long long  int> &v,unsigned long long int  k,unsigned long long int  b) ;
 
unsigned long long  int qwertyuiop(vector<unsigned long long  int> &ver,unsigned long long int  k,unsigned long long int  b) {
    if (ver.size() == 0)
        return 0;
    map<unsigned long long int ,unsigned long long  int> mp;
    vector<unsigned long long int > tailer(ver.size(), 0);
    unsigned long long int  length = 1;
 
    tailer[0] = ver[0];
    for (unsigned long long int i = 1; i < ver.size(); i++) {
        if (ver[i] < tailer[0])
           {
            mp[ver[i]]=0;
            tailer[0] = ver[i];
        }
        else if (ver[i] >= tailer[length-1])
            {
                if(ver[i] >= k*tailer[length-1]+b)
            {tailer[length] = ver[i]; mp[ver[i]]=length; length++; }
        }
        else
           { 
            unsigned long long int  index;
            if(mp.find(ver[i])!=mp.end()) index=mp[ver[i]]+1;
            else index=dfghjkl(tailer, -1, length-1, ver[i]);
            int jkl=k*tailer[index-1]+b;
            if(jkl<=ver[i])
              {tailer[index] = ver[i]; mp[ver[i]]=index; }
        }
    }
 
    return length;
}
 
unsigned long long int  dfghjkl(vector<unsigned long long int > &v, unsigned long long int lty, unsigned long long int r, unsigned long long int key) {
    while (r-lty > 1) 
    {
    unsigned long long  int m = lty + (r-lty)/2;
    if (v[m] >= key)
        r = m;
    else
        lty = m;
    }
 
    return r;
}
 
 
int main() {
    unsigned long long int  t;
 
    cin>>t;
    while(t--)
    {
        unsigned long long int n,k,b;
        cin>>n>>k>>b;
        vector<unsigned long long int> vec(n);
        for (unsigned long long int  i = 0; i < n; ++i)
        {
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());
        if(k!=0)
        cout<<qwertyuiop(vec,k,b)<<endl;
        else
        {
            int ui=0;
            for (int i = 0; i < vec.size(); ++i)
            {
                if(vec[i]>=b) ui++;
            }
            if(ui==vec.size()) cout<<ui<<endl;
            else cout<<ui+1<<endl;
        }
    }
   return 0;
} 