#include <bits/stdc++.h>
using namespace std;
#define MU 123
#define ULL unsigned long long
ULL hash[1000009];
void preHash(char str[] , int n)
{
    hash[n] = 0;
    for(int i = n-1 , j = 1 ; i>=0 ; i-- , j++){
        hash[i] = hash[i+1]*MU + str[i] - 97;
    }
}
void solve(char text[] , char pattern[] , int p , int t){
    ULL p_hash = 0 , check , pre = 1;
    for(int i = p-1 ; i>=0 ; i--){
        p_hash = p_hash*MU + pattern[i] - 97;
        pre = pre*MU;
    }
    check = p_hash;
    vector<int> v;
    int flag = 0;
    preHash(text , t);
    for(int i = 0; i < t - p + 1 ; i++ )
        if(hash[i] - pre*hash[i+p] == check){
            flag++;
            v.push_back(i+1);
        }
    if(flag == 0)
        printf("Not Found\n");
    else
    {
        printf("%d\n",flag);
        for(int i = 0 ; i < flag ; i++)
            printf("%d ",v[i]);
        printf("\n");
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char text[1000009] ,  pattern[1000009];
        scanf("%s%s",text , pattern);
        int n , m ;
        n = strlen(text);
        m = strlen(pattern);
        solve(text , pattern , m , n);
    }
    return 0;
}
