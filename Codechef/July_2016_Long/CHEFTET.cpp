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

bool solve(ll * a, ll * b, ll n, ll total){ // checks if all values are same as total

    ll c = 0;

    // consider 1st element
    if (a[0] == total) {c++;}
    else if (a[0]+b[0]==total) {c++;}
    else if (a[0]+b[1]==total) {c++;}
    else if (a[0]+b[0]+b[1]==total) {c++;}
    else return false;


    // consider mid elements
    for (ll i = 1; i < n -1; i++) {
        li diff = total - a[i];
        if (diff < 0) return false;
        else if (diff == 0) {c++;}
        else if (diff == b[i-1]) {c++;}
        else if (diff == b[i]) {c++;}
        else if (diff == b[i-1]+b[i]) {c++;}
        else if (diff == b[i+1]) {c++;}
        else if (diff == b[i]+b[i+1]) {c++;}
        else if (diff == b[i-1]+b[i+1]) {c++;}
        else if (diff == b[i-1]+b[i]+b[i+1]) {c++;}
        else return false;
    }


    // consider for last element
    if (a[n-1] > total) return false;
    else if (a[n-1] == total) {c++;}
    else if (a[n-1]+b[n-2]==total) {c++;}
    else if (a[n-1]+b[n-1]==total) {c++;}
    else if (a[n-1]+b[n-2]+b[n-1]==total) {c++;}
    else return false;

    return true;
}   


int main() {
    // freopen("input", "r", stdin);
    int t;
    cin >> t;
    while (t--){

        ll n;
        cin >> n;
        ll a[n], b[n];
        
        FOR(n) cin >> b[i];
        FOR(n) cin >> a[i];

        if (n == 1) {
            cout << a[0] + b[0] << endl;
            continue;
        }


        ll ans1 = a[0] + b[0];
        ll ans2 = a[0] + b[1];
        ll ans3 = ans1 + b[1];

        if (ans2 < ans1) swap(ans1, ans2);

        if (solve(a,b,n, ans3)) {cout << ans3 << endl; continue;}
        if (solve(a,b,n, ans2)) {cout << ans2 << endl; continue;}
        if (solve(a,b,n, ans1)) {cout << ans1 << endl; continue;}
        if (solve(a,b,n, a[0])) {cout << a[0] << endl; continue;}

        cout << "-1\n";

    }


}