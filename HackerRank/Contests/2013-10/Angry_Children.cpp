#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main()
{	long long int n,k;
	cin>>n>>k;
	vector<long long int>ref;
	for (long long int i=0;i<n;i++)
	{	long long int j;
	cin>>j;
	ref.push_back(j);
	}
	sort(ref.begin(),ref.end());
	long long int min = ref[n-1]-ref[0];
	for (long long int i=0; i<=n-k;i++)
	{	long long int t = ref[i+k-1]-ref[i];
		if (t<min)
			min = t;
	}
	cout<<min<<endl;
	return 0;
}
