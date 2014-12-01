#include<bits/stdc++.h>
using namespace std;

#define FOR(a) for(int i=0; i<a;i++)

int main()
{   //freopen("in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long int c = 0;
        cin >> n;
        int a[n];
        FOR(n) {
            string x;
            cin >> x;
            cin >> a[i];
        }
        sort(a, a+n);
        FOR(n) {
            c+= abs(i+1 - a[i]);
        }
        cout << c << endl;
    }
    return 0;

}
