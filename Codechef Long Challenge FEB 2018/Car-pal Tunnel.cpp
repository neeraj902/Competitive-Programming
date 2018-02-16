#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>arr[i];
        }
        long long int c,d,s;
        cin>>c>>d>>s;
        long long int curdis=0;
        for (int i = 0; i < n; ++i)
        {
            if(curdis<arr[i]) curdis=arr[i];
        }
        cout<<(c-1)*curdis<<endl;
    }
    return 0;
} 