#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

#define inp_s     ios_base::sync_with_stdio(false)
#define DRT()     int t;cin>>t;while(t--)
#define DEBUG_IN  freopen("in", "r", stdin)

#define VI        vector<int>
#define VS        vector<string>
#define VLL       vector<LL>
#define PII       pair<int,int>
#define all(c)    c.begin(),c.end()
#define sz(c)     c.size()
#define clr(c)    c.clear()
#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define GI(x)     scanf("%d",&x);
#define GLL(x)    scanf("%lld",&x);
#define GSTR(x)   scanf("%s",x);

#define PI(x)     printf("%d",x);
#define PLL(x)    printf("%lld",x);
#define PSTR(x)   printf("%s",x);

#define FOR(i,a,b)      for(int i=a;i<b;i++)
#define RFOR(i,a,b)     for(int i=b-1;i>=a;i--)
#define FOR(a)    for(int i=0; i<a;i++)

#define gcd(a,b)  __gcd(a,b)
#define MOD       1000000007

int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{   //DEBUG_IN;
	int p[32][32], n,m, x,y;
	cin >> n >> m >> x >> y;
	for (int i = 0; i <= n; i++) p[i][0] =-1;
	for (int j = 0; j <= m; j++) p[0][j] = -1;

	for (int i = 1; i <=n ; i++)
	{   for (int j = 1; j <= m; j++)
        {    cin >> p[i][j];
             if (i < x || j < y) p[i][j] = -1;
        }
	}


	for (int i = x; i <= n; i++)
	{
        for (int j = y; j <= m; j++) {

            if (i == x && j == y) continue;
            else {
                int v = maximum(p[i-1][j], p[i][j-1]);
                p[i][j] = v - p[i][j];
            }
        }


    }
    if (p[n][m] >= 0) cout << "Y " << p[n][m] << endl;
    else cout << "N\n";


}
