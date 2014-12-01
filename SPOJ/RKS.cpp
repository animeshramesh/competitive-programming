#include<bits/stdc++.h>
using namespace std;

#define FOR(a) for(int i=0; i<a;i++)
#define LL long long int

#define MAX 1001


map<LL, LL> firstOccurence, freq;

bool compare(LL x, LL y) {

    if (freq[x] == freq[y])
        return (firstOccurence[x] < firstOccurence[y]);
    return freq[x] > freq[y];
}
int main()
{   freopen("in", "r", stdin);
    LL n, c;
    cin >> n >> c;
    LL a[n];
    FOR(n) {
        cin >> a[i];
        freq[a[i]]++;
        if (freq.find(a[i]) == freq.end())
            freq[a[i]] = 1;
        else
            freq[a[i]] = freq[a[i]] + 1;
        if (firstOccurence.find(a[i]) == firstOccurence.end())
            firstOccurence[a[i]] = i;
    }

    sort(a, a+n, compare);
    FOR(n)
        cout << a[i] << " ";

}
