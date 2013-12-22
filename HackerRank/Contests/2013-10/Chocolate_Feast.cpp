#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,c,m;
        cin>>n>>c>>m;
        int tot=0;
        tot+=n/c;
        n=tot;
        while(n>=m)
        {
            tot+=n/m;
            n=n/m+(n%m);
        }
        cout<<tot<<endl;
    }
    return 0;
}

