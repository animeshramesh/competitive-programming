#include <bits/stdc++.h>

using namespace std;

int maximum (int a, int b)
{
    if (a > b) return a;
    return b;
}
int main()
{   freopen("in", "r", stdin);
    int k;
    cin >> k;
    while (k > 0) {
        string s1, s2;
        cin >> s1 >> s2;
        int m = s1.length(), n = s2.length();
        int dp[m+1][n+1];
        cout << "DP Matrix\n";
        for (int i = 0; i <= m; i++)
        {   for (int j = 0; j <=n ; j++)
            {   if (i == 0 || j == 0 ) {dp[i][j] = 0;}
                else {
                    if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                    else dp [i][j] = maximum(dp[i-1][j], dp[i][j-1]);
                }
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        int ma = -1, coun=0;

        for (int i = 1; i<=m; i++)
        {   coun = 0;
            for (int j = 1; j<=n; j++)
            {
                if (dp[i][j] == dp[i][j-1]+1)
                {
                    coun++;
                    if (coun > ma) ma = coun;

                }
                else coun = 0;

            }

        }
        cout << ma << endl;
        cin >> k;
    }

}
