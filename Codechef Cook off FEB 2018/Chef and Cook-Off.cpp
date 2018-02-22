#include<bits/stdc++.h>
using namespace std;
int main()
{
 
    int n;
    cin>>n;
    string arr[6];
 
    arr[0]="Beginner";
    arr[1]="Junior Developer";
    arr[2]="Middle Developer";
    arr[3]="Senior Developer";
    arr[4]="Hacker";
    arr[5]="Jeff Dean";
 
    for (int i = 0; i < n; ++i)
    {   int jkl=0;
       for(int j=0;j<5;j++)
       {
         int h;
         cin>>h;
         jkl+=h;
       }
       cout<<arr[jkl]<<endl;
    }
 
    
    return 0;
} 