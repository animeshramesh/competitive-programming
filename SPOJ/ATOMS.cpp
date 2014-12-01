#include<bits/stdc++.h>
using namespace std;

#define FOR(a) for(int i=0; i<a;i++)
#define LL long long int

int main()
{   //freopen("in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, m, k;
        cin >> n >> k >> m;
        if (m <= n) {
            cout << "0\n";
            continue;
        }
        float result = log(m/n)/log(k);

        printf("%d\n", (int)result);

    }
    return 0;

}

