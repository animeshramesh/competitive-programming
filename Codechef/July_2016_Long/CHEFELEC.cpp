#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(ll i=0; i<(n); i++)
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define mem(x,val) memset((x),(val),sizeof(x));
#define rite(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define clr clear()
#define inf (1<<30)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9
typedef long long ll;
typedef long int li;
typedef unsigned long long ull;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef set<int> si;
typedef set<st> ss;  


void debug(string a, ll val) {
    cout << a << " : " << val << endl;
}

int main() {
    // freopen("input", "r", stdin);
    int t;
    cin >> t;
    while (t--){

        ll n, cost=0;
        cin >> n;
        
        string a;
        ll x[n];

        cin >> a;
        FOR(n) cin >> x[i];

        ll i = 0, firstOne = 0, lastOne = n-1;

        // Make all initial 0's as 1
        while (i<n)
        {
            if (a[i] == '0')  {
                cost += x[i+1] - x[i];
                a[i] = 1;
            } else {
                firstOne = i;
                break;
            }
            i++;
        }
        // debug("Cost", cost);

        // Make all trailing 0s as 1
        i=n-1;
        while (i >0) 
        {
            if (a[i] == '0') 
            {
                cost += x[i] - x[i-1];
                a[i] = 1;
            }
            else {
                lastOne = i;
                break;
            }
            i--;
        }

        ll l = firstOne, r=lastOne;
        while (l<=r)
        {
            if (a[l]=='1') {l++; continue;}
            if (a[r]=='1') {r--; continue;}
            


        }

        // Analyze middle elements
        // for (i=firstOne+1; i<lastOne; i++)
        // {
        //     if (a[i]=='0')
        //     {   ll lcost = x[i]-x[i-1];
        //         if (a[i+1] == '1') 
        //         {   ll rcost = x[i+1]-x[i];
        //             if (lcost < rcost) cost += lcost;
        //             else cost += rcost;
        //             a[i]=1;
        //         }
        //         else 
        //         {
        //             ll rpos = i; // Index of 1 on the right
        //             while (rpos<n && a[rpos]=='0')
        //             {
        //                 rpos++;
        //             }
        //             // ll rcost = x[rpos] - x[rpos-1];
        //             ll rcost = (x[rpos] - x[i])/(rpos-i);
        //             if (lcost<rcost) {cost += lcost; a[i]=1;}
        //             else {
        //                 cost += x[rpos]-x[i];
        //                 a[i]=1;
        //                 i = rpos;
        //             }
        //         }
        //     }
        // }

        cout << cost << endl;

    }


}