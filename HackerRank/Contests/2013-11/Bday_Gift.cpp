#include<iostream>
#include<cmath>
#include<cstdio>
 using namespace std;

 int main()
 {

         int n;
         long double s=0;
         cin>>n;
         long long int a[n];
         for (int i=0; i<n;i++)
         {
             cin>>a[i];
             s+=a[i]/2.0;
         }

         printf("%.1llf\n",s);



 }

