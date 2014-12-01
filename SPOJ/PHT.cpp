#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int t, i;
    long long m;
    double n;
    scanf("%d", &t);
    printf("\n");
    for(i = 1; i <= t; i++) {
        scanf("%lf", &n);
        m = (long long)floor(sqrt(n));
        if ((m * (m + 2)) > n) m--;
        printf("Case %d: %d\n\n", i, m);
    }

    return 0;
}
