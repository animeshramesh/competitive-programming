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

int main()
{   //DEBUG_IN;
    char c[1005];
    int coun = 0;
    cin.getline(c, 1005);
    bool alphas[26] = {false};
    FOR(strlen(c)) {

        if (isalpha(c[i])) {
            char x = tolower(c[i]);
            int index = x - 97;
            if (!alphas[index]) {
                alphas[index] = true;
                coun ++;
            }
        }
    }
    if (coun == 26) cout <<"pangram\n";
    else cout << "not pangram\n";


}
