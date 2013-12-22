#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MOD 1000000007


int main()
{   //freopen("liin.txt","r",stdin);

        int size;
        cin>>size;
        vector<int> ref;
        for (int i=0; i<size;i++)
        {
            int k;
            cin>>k;
            if (find(ref.begin(),ref.end(),k)==ref.end())
                ref.push_back(k);
            else
                ref.erase(find(ref.begin(),ref.end(),k));
        }
        cout<<ref[0]<<endl;

}

