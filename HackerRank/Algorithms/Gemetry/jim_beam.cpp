
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
const double EPS = 0.00001;

struct Point
{
    double
     x,y;
};

struct Line
{
    Point p1, p2;
};

double maxi (LL a, LL b)
{   if (a>b) return a;
    return b;
}

double mini (LL a, LL b)
{   if (a<b) return a;
    return b;
}

bool isIntersecting(Line l1, Line l2) {

    double A1, B1, C1, A2, B2, C2;

    A1 = l1.p2.y - l1.p1.y;
    B1 = l1.p1.x - l1.p2.x;
    C1 = A1*l1.p1.x + B1*l1.p1.y;

    if ((A1*(l2.p1.x) + B1*(l2.p1.y) - C1 == 0) && (A1*(l2.p2.x) + B1*(l2.p2.y) - C1 == 0))
    {
        if ((l2.p1.x >= mini(l1.p1.x, l1.p2.x)) && (l2.p1.x <= maxi(l1.p1.x, l1.p2.x)))
            return true;
        if ((l2.p2.x >= mini(l1.p1.x, l1.p2.x)) && (l2.p2.x <= maxi(l1.p1.x, l1.p2.x)))
            return true;
    }

    A2 = l2.p2.y - l2.p1.y;
    B2 = l2.p1.x - l2.p2.x;
    C2 = A2*l2.p1.x + B2*l2.p1.y;


    double det = A1*B2 - A2*B1;
    if(det == 0){
        //Lines are parallel
        return false;
    }else{
        double x = (B2*C1 - B1*C2)/det;  // point of intersection
        double y = (A1*C2 - A2*C1)/det;
        //cout << "\nPoint of intersection is (" << x << ", " <<y << ")\n";
        if (x < mini(l1.p1.x, l1.p2.x) || x > maxi(l1.p1.x, l1.p2.x)) return false;
        if (x < mini(l2.p1.x, l2.p2.x) || x > maxi(l2.p1.x, l2.p2.x)) return false;
        if (y < mini(l1.p1.y, l1.p2.y) || y > maxi(l1.p1.y, l1.p2.y)) return false;
        if (y < mini(l2.p1.y, l2.p2.y) || y > maxi(l2.p1.y, l2.p2.y)) return false;
    }
    return true;

}
int main(){
    DEBUG_IN;
    DRT()
    {
        Point mirror, wall1, wall2;
        Line mLine, wLine;
        cin >> wall1.x >> wall1.y >> wall2.x >> wall2.y >> mirror.x >> mirror.y;
        wLine.p1 = wall1;
        wLine.p2 = wall2;
        mLine.p1 = mirror;
        mLine.p2.x = 0;
        mLine.p2.y = 0;
        if (isIntersecting(mLine, wLine)) cout << "NO\n";
        else cout << "YES\n";

    }
}
