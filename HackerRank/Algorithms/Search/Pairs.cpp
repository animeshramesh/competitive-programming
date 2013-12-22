#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    long long int n,k,count=0;
    cin>>n>>k;
    long long int ref[n];
    for (long long int i=0; i<n;i++)
        cin>>ref[i];
    sort(ref,ref+n);
    for (long long int i=0; i<n-1;i++)
    {
        for (long long int j=i+1;j<n;j++)
        {
            if (abs(ref[j]-ref[i])==k)
                count++;
            if (abs(ref[j]-ref[i])>k)
                break;
            
        }
    }
    cout<<count<<endl;
}

