#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

#define inp_s     ios_base::sync_with_stdio(false)
#define DRT()     int t;cin>>t;while(t--)
#define DEBUG_IN  freopen("in", "r", stdin)

#define VI        vector<int>
#define VS        vector<string>
#define VLL       vector<LL>/home/animesh/git/competitive-programming/LightOJ/triangle_partitioning.cpp
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

#define MAX 20010;
#define V 1 //Vampire
#define L (-1) //Lycan
#define U 0 //undefined

VI rivals[MAX];
int team[MAX];

bool DFS(int r){



}
int main()
{   int k=0;
	DRT() {
        k++;
        int fights, max_rival=0;
        cin >> fights;
        for (int i = 0; i < MAX; i++) {
            team[i] = U;
            rivals[i].clear();
        }
        FOR(fights) {
            int m,n;
            cin >> m >> n;
            if (max_rival < m) max_rival = m;
            if (max_rival < n) max_rival = n;

            rivals[m].push_back(n);
            rivals[n].push_back(m);

        }
        for (int i = 1; i<max_rival; i++)
        {
            if (team[i]==U) {
                team[i] = V;
                result = result and DFS(i);
            }

        }
	}

}
