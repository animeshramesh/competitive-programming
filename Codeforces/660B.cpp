#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i=0; i<(n); i++)
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
typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef set<int> si;
typedef set<st> ss;


int main() {
    
    int n, m, seated = 1;
    cin >> n >> m;

    vi lw, la, rw, ra;

    while (seated <= m) {

        if (seated % 2 != 0) { 
            if (sz(lw) < n) lw.pb(seated);
            else la.pb(seated); 
        } 

        else {
            if (sz(rw) < n) rw.pb(seated);
            else ra.pb(seated);
        }

        seated ++ ;
    }

    FOR(n) {
        if (i<sz(la)) cout << la[i] << " ";
        if (i<sz(lw)) cout << lw[i] << " ";
        if (i<sz(ra)) cout << ra[i] << " "; 
        if (i<sz(rw)) cout << rw[i] << " ";   
    }

}