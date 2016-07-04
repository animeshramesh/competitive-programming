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
typedef unsigned long long ull;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef set<int> si;
typedef set<st> ss;


int main() {
    
    int t;
    cin >> t;
    while (t--){

    	bool hasGPA = false, hasFailed = false;
    	ll n, fullScores = 0, sum = 0;
    	
    	cin >> n;
    	vi grades(n);

    	FOR(n) {
    		cin >> grades[i];
    		if (grades[i] == 2) hasFailed = true;
    		else if (grades[i] == 5) fullScores++;
    		sum += grades[i];
    	}

    	if (double(sum/n) >= 4) hasGPA = true;

    	if (fullScores > 0 && !hasFailed && hasGPA) cout << "Yes\n";
    	else cout << "No\n";

    }


}