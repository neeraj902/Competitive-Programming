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
        vector<char> vec;
        for (int i = 0; i < s.length(); ++i)
        {
            if(('a'<=s[i] && 'z'>=s[i])||('A'<=s[i] && 'Z'>=s[i]))
 
            {
 
                vec.push_back(s[i]);
                if('A'<=vec[vec.size()-1] && 'Z'>=vec[vec.size()-1])
                    vec[vec.size()-1]+=32;
            }
        }
        int county=0;
        
        int ui=vec.size()-4;
        for (int i = 0; i <= ui; ++i)
        {
            vector<char> v;
            v.push_back(vec[i]);
            v.push_back(vec[i+1]);
            v.push_back(vec[i+2]);
            v.push_back(vec[i+3]);
            sort(v.begin(),v.end());
            if(v[0]=='c' && v[1]=='e' && v[2]=='f' && v[3]=='h')
            {
                county++;
            }
        }
        if(county!=0)
        {
            cout<<"lovely "<<county<<endl;
        }
        else
        {
            cout<<"normal\n";
        }
 
 
 
    }
    return 0;
}  