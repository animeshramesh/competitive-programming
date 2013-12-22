#include<iostream>
 using namespace std;

 int main()
 {
     int t;
     cin>>t;
     while (t--)
     {
         int n;
         cin>>n;
         int k = 1;
         for (int i = 1; i<=n; i++)
         {
             if (i%2!=0)
                k=2*k;
            else
                k++;
         }
         cout<<k<<endl;
     }

 }

