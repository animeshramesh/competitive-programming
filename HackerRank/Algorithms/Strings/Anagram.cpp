#include<iostream>
#include<vector>
#include<ctype.h>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        char str[10005];
        cin>>str;
        for (int i=0; i<strlen(str);i++)
            tolower(str[i]);
        if (strlen(str)%2!=0)
        {
            cout<<"-1\n";
            continue;
        }
        vector<int>a(26,0);
        vector<int>b(26,0);
        for (int i=0; i<strlen(str)/2;i++)
        {
            a[str[i]-97]++;
        }
        for (int i=strlen(str)/2;i<strlen(str);i++)
            b[str[i]-97]++;
        int flag=0;
        for (int i=0; i<26;i++)
        {
            if (a[i]!=b[i])
                flag+=abs(a[i]-b[i]);

        }
        cout<<flag/2<<endl;
    }
}

