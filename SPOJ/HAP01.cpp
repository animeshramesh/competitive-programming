#include<iostream>
#include<cmath>

using namespace std;

int bin(long long int n)
{   int co = 0, ce = 0, i = 0;
    while (n >  0)
    {   if (n & 1)
        {   if (i % 2 == 0) ce ++;
            else co++;
        }
        n = n >> 1;
        i ++;
    }
    return abs(co-ce);
}

int main()
{   int t;
    cin >> t;
    while (t--)
    {   long long int n,m,c=0,k;
        cin >> m >> n >> k;
        for (long long int i = m; i<=n; i++)
            if (bin(i) == k) c++;
        cout << c << endl;
    }
}
