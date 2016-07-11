// Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
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
typedef long long ll;
typedef unsigned long long ull;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef set<int> si;
typedef set<st> ss;


// knapsackRecursive() finds the maximum value that can be obtained for a bag with weight W
// n => number of items allowed in the bag
int knapsackRecursive(int weightOfBag, int n, int weights[], int values[])
{
	if (weightOfBag == 0 || n == 0) return 0;

	// Do not include 'n'th item if its weight is greater than that of the bag
	if (weights[n-1] > weightOfBag) return knapsackRecursive(weightOfBag, n-1, weights, values);

	int costA = values[n-1] + knapsackRecursive(weightOfBag-weights[n-1], n-1, weights, values); // cost of including the 'n'th item
	int costB = knapsackRecursive(weightOfBag, n-1, weights, values);	// cost of not including the 'n'th item

	return max(costA, costB);
}

// Iterative memoization method
// Time complexity => O(nW)
int knapsack(int weightOfBag, int n, int weights[], int values[])
{
   	int K[n+1][weightOfBag+1];
 
   	// Build table K[][] in bottom up manner
   	for (int i = 0; i <= n; i++)
   	{
    	for (int j= 0; j <= weightOfBag; j++)
       	{
        	if (i==0 || j==0)
            	K[i][j] = 0;
            else if (weights[i-1] <= j)
                K[i][j] = max(values[i-1] + K[i-1][j-weights[i-1]],  K[i-1][j]);
           	else
                K[i][j] = K[i-1][j];
       }
   }
 
   return K[n][weightOfBag];

}

int main() {
    
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
	
	cout << knapsack(W, n, wt, val);
	
    return 0;

}